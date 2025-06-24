#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "class.h"

using namespace std;

Basics *p[100]; //基类指针,用于存储账户信息
int count = 0; //账户数量

void initialize() //初始化系统
{
    ifstream fin;
    fin.open("user_data.txt", ios::in); //打开文件
    if (!fin)
    {
        cout << "系统初始化错误！" << endl;
        exit(1);
    }
    fin >> count; //读取账户数量
    for (int i = 0; i < count; i++)
    {
        int type;
        string name;
        long long cardNum;
        double balance;
        fin >> type;
        if(type == 1) //借记卡
        {
            double rate;
            fin >> name >> cardNum >> balance >> rate;
            p[i] = new Debit(name, cardNum, balance, rate);
        }
        else if (type == 2) //信用卡
        {
            double maxLoan, rates, debt;
            fin >> name >> cardNum >> balance >> maxLoan >> rates >> debt;
            Credit *c = new Credit(name, cardNum, balance, maxLoan, rates);
            c->setDebt(debt); //设置欠款
            p[i] = c; //基类指针指向派生类对象
        }
    }
    fin.close();

    fin.open("record.txt", ios::in); //打开交易记录文件
    if (!fin)
    {
        cout << "交易记录文件打开失败！" << endl;
        exit(1);
    }
    string time, type;
    double amount, balance, debt;
    long long cardNum;
    while(fin >> time >> type >> amount >> cardNum >> balance >> debt)
    {
        if(fin.eof()) //文件结束
            break;
        for (int i = 0; i < count; i++)
        {
            if (p[i]->getCardNum() == cardNum)
            {
                p[i]->addRecord(time, type, amount, cardNum, balance, debt); //添加交易记录
                break;
            }
        }
    }
    fin.close();
}

void build() //创建账户
{
    if (count >= 100)
    {
        cout << "账户已满，无法创建新账户！" << endl;
        return;
    }
    cout << "请选择账户类型: 1.借记卡 2.信用卡" << endl;
    int type;
    while(cin >> type)
    {
        if (type == 1 || type == 2)
            break;
        cout << "输入错误，请重新输入：";
    }
    string name;
    long long cardNum;
    double balance;
    cout << "请输入姓名：";
    while(cin >> name)
    {
        if (name.length() > 0 && name.length() <= 20)
            break;
        cout << "姓名长度不合法，请重新输入：";
    }
    cout << "请输入卡号：";
    while(cin >> cardNum)
    {
        if (cardNum <= 0 || cardNum >= 10000000000000000) //卡号合法性检查
        {
            cout << "卡号不合法，请重新输入：";
            continue;
        }
        bool exists = false;
        for (int i = 0; i < count; i++)
        {
            if (p[i]->getCardNum() == cardNum) //检查卡号是否已存在
            {
                exists = true;
                break;
            }
        }
        if (!exists)
            break;
        cout << "卡号已存在，请重新输入：";
    }    
    
    cout << "请输入初始余额：";
    while(cin >> balance)
    {
        if (balance >= 0)
            break;
        cout << "余额不合法，请重新输入：";
    }

    if (type == 1) //借记卡
    {
        double rate;
        cout << "请输入利率：";
        while(cin >> rate)
        {
            if (rate >= 0)
                break;
            cout << "利率不合法，请重新输入：";
        }
        p[count] = new Debit(name, cardNum, balance, rate);
        count++;
        cout << "借记卡账户创建成功！" << endl;
    }
    else //信用卡
    {
        double maxLoan, rates;
        cout << "请输入最大贷款额度：";
        while(cin >> maxLoan)
        {
            if (maxLoan >= 0)
                break;
            cout << "最大贷款额度不合法，请重新输入：";
        }
        cout << "请输入利率：";
        while(cin >> rates)
        {
            if (rates >= 0)
                break;
            cout << "利率不合法，请重新输入：";
        }
        p[count] = new Credit(name, cardNum, balance, maxLoan, rates);
        count++;
        cout << "信用卡账户创建成功！" << endl;
    }
}

void deposit() //存款
{
    long long cardNum;
    double amount;
    cout << "请输入卡号：";
    while(cin >> cardNum)
    {
        for (int i = 0; i < count; i++)
        {
            if (p[i]->getCardNum() == cardNum)
            {
                cout << "请输入存款金额：";
                while(cin >> amount)
                {
                    if(p[i]->Deposit(amount)) //存款
                    {    
                        cout << "存款成功！" << endl;
                        return;
                    }
                    else
                        cout << "存款失败，请重新输入金额：";
                }
            }
        }
        cout << "账户不存在，请重新输入卡号：";
    }
}

void withdraw() //取款
{
    long long cardNum;
    double amount;
    cout << "请输入卡号：";
    while(cin >> cardNum)
    {
        for (int i = 0; i < count; i++)
        {
            if (p[i]->getCardNum() == cardNum)
            {
                cout << "请输入取款金额：";
                while(cin >> amount)
                {
                    if(p[i]->Withdraw(amount)) //取款
                    {
                        cout << "取款成功！" << endl;
                        return;
                    }    
                    else
                        cout << "取款失败，请重新输入金额：";
                }
            }
        }
        cout << "账户不存在，请重新输入卡号：";
    }
}

void show() //显示账户信息
{
    long long cardNum;
    cout << "请输入卡号：";
    cin >> cardNum;

    for (int i = 0; i < count; i++)
    {
        if (p[i]->getCardNum() == cardNum)
        {
            p[i]->Show(); //显示账户信息
            return;
        }
    }
    cout << "账户不存在！" << endl;
}

void showRecord() //显示交易记录
{
    long long cardNum;
    cout << "请输入卡号：";
    while(cin >> cardNum)
    {
        for (int i = 0; i < count; i++)
        {
            if (p[i]->getCardNum() == cardNum)
            {
                p[i]->ShowRecords(); //显示交易记录
                return;
            }
        }
        cout << "账户不存在，请重新输入卡号：";
    }
}

void save() // 保存账户信息
{
    ofstream fout;
    fout.open("user_data.txt", ios::out | ios::trunc); //重新写入数据
    if (!fout)
    {
        cout << "系统保存错误！" << endl;
        exit(1);
    }
    fout << count << endl; //写入账户数量
    for (int i = 0; i < count; i++)
    {
        if (Debit *d = dynamic_cast<Debit *>(p[i])) //查看是否安全转换
        {
            fout << 1 << " " << d->getName() << " " << d->getCardNum() << " " << d->Balance() << " " << d->getRate() << endl;
        }
        else if (Credit *c = dynamic_cast<Credit *>(p[i]))
        {
            fout << 2 << " " << c->getName() << " " << c->getCardNum() << " " << c->Balance() << " " << c->getMaxLoan() << " " << c->getRates() << " " << c->getDebt() << endl;
        }
    }
    fout.close();

    fout.open("record.txt", ios::out | ios::trunc); //重新写入交易记录
    if (!fout)
    {
        cout << "交易记录保存错误！" << endl;
        exit(1);
    }
    for (int i = 0; i < count; i++)
    {
        const vector<Record> &records = p[i]->getRecords(); //获取交易记录
        for (const auto &record : records)
        {
            fout << record.toString() << endl; //写入交易记录
        }
    }
    fout.close();

    for(int i = 0; i < count; i++) //释放内存
    {
        delete p[i];
    }
}

