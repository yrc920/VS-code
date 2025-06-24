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
        massage user;
        long long cardNum;
        string password;
        double balance;
        fin >> type;
        if(type == 1) //借记卡
        {
            double rate;
            fin >> user >> cardNum >> password >> balance >> rate;
            p[i] = new Debit(user, cardNum, password, balance, rate); //创建借记卡对象
        }
        else if (type == 2) //信用卡
        {
            double maxLoan, rates, debt;
            fin >> user >> cardNum >> password >> balance >> maxLoan >> rates >> debt;
            Credit *c = new Credit(user, cardNum, password, balance, maxLoan, rates);
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
        cout << "账户已满,无法创建新账户！" << endl;
        return;
    }
    cout << "请选择账户类型: 1.借记卡 2.信用卡" << endl;
    int type;
    while(cin >> type)
    {
        if (type == 1 || type == 2)
            break;
        cout << "输入错误,请重新输入：";
    }

    massage user; //用户信息
    long long cardNum;
    string password;
    double balance;
    user = user.build(); //创建用户信息
    cout << "请输入卡号: ";
    while(cin >> cardNum)
    {
        if (cardNum <= 0 || cardNum >= 10000000000000000) //卡号合法性检查
        {
            cout << "卡号不合法,请重新输入：";
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
        cout << "卡号已存在,请重新输入：";
    }    
    cout << "请输入密码: ";
    while(cin >> password)
    {
        if (password.length() >= 4 && password.length() <= 20)
            break;
        cout << "密码长度不合法,请重新输入：";
    }
    cout << "请输入初始余额: ";
    while(cin >> balance)
    {
        if (balance >= 0)
            break;
        cout << "余额不合法,请重新输入：";
    }

    if (type == 1) //借记卡
    {
        double rate;
        cout << "请输入利率：";
        while(cin >> rate)
        {
            if (rate >= 0)
                break;
            cout << "利率不合法,请重新输入：";
        }
        p[count] = new Debit(user, cardNum, password, balance, rate);
        count++;
        cout << "借记卡账户创建成功！" << endl;
    }
    else //信用卡
    {
        double maxLoan, rates;
        cout << "请输入最大贷款额度:";
        while(cin >> maxLoan)
        {
            if (maxLoan >= 0)
                break;
            cout << "最大贷款额度不合法,请重新输入：";
        }
        cout << "请输入利率：";
        while(cin >> rates)
        {
            if (rates >= 0)
                break;
            cout << "利率不合法,请重新输入：";
        }
        Credit *c = new Credit(user, cardNum, password, balance, maxLoan, rates);
        c->setDebt(0); //设置欠款为0
        p[count] = c; //基类指针指向派生类对象
        count++;
        cout << "信用卡账户创建成功！" << endl;
    }
}

int enter1() //用户登录
{
    int i = 0;
    long long cardNum;
    cout << "请输入卡号: ";
    while(cin >> cardNum && i < 2) //最多输入三次
    {
        i++;
        for (int j = 0; j < count; j++)
        {
            if (p[j]->getCardNum() == cardNum)
            {
                int n = 0;
                string password;
                cout << "请输入密码: ";
                while(cin >> password && n < 2) //最多输入三次
                {
                    n++;
                    if (p[j]->checkPassword(password)) //检查密码是否正确
                    {
                        cout << "登录成功！" << endl;
                        return j; //返回账户索引
                    }
                    cout << "密码错误,请重新输入: ";
                }
                cout << "输入错误次数过多! " << endl;
                return -1; //返回-1表示登录失败
            }
        }
        cout << "账户不存在,请重新输入卡号: ";
    }
    cout << "输入错误次数过多! " << endl;
    return -1; //返回-1表示登录失败
}

void deposit(int i) //存款
{
    double amount;
    cout << "请输入存款金额: ";
    while (cin >> amount)
    {
        if (p[i]->Deposit(amount)) // 存款
        {
            cout << "存款成功！" << endl;
            return;
        }
        else
            cout << "存款失败,请重新输入金额：";
    }
}

void withdraw(int i) //取款
{
    double amount;
    cout << "请输入取款金额: ";
    while (cin >> amount)
    {
        if (p[i]->Withdraw(amount)) // 取款
        {
            cout << "取款成功！" << endl;
            return;
        }
        else
            cout << "取款失败,请重新输入金额: ";
    }
}

void show(int i) //显示账户信息
{
    p[i]->Show();
}

void showRecord(int i) //显示交易记录
{
    cout << "交易记录:" << endl;
    p[i]->ShowRecords();
}

void amendPassword(int i) //修改密码
{
    string password1;
    cout << "请输入新密码: ";
    while (cin >> password1)
    {
        if (password1.length() >= 4 && password1.length() <= 20)
        {
            cout << "请输确认密码: ";
            string Password2;
            cin >> Password2;
            if (password1 == Password2) //确认密码
            {
                p[i]->setPassword(password1); //设置新密码
                cout << "密码修改成功！" << endl;
                return;
            }
            else
                cout << "两次输入的密码不一致,请重新输入: ";
        }
        else
            cout << "密码长度不合法,请重新输入：";
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
        if(Debit *d = dynamic_cast<Debit *>(p[i])) //借记卡
        {
            fout << 1 << " " << d->getUser() << " " << d->getCardNum() << " " << d->getPassword() << " " << d->Balance() << " " << d->getRate() << endl; //写入借记卡信息
        }
        else if (Credit *c = dynamic_cast<Credit *>(p[i])) //信用卡
        {
            fout << 2 << " " << c->getUser() << " " << c->getCardNum() << " " << c->getPassword() << " " << c->Balance() << " " << c->getMaxLoan() << " " << c->getRates() << " " << c->getDebt() << endl; //写入信用卡信息
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
}

void cleanup() //清理内存
{
    for (int i = 0; i < count; i++)
    {
        delete p[i]; //释放内存
    }
}

bool enter2() //管理员登录
{
    int i = 0;
    string password;
    cout << "请输入管理员密码: ";
    while (cin >> password && i < 2) //最多输入三次
    {
        i++;
        if (password == "0920") //管理员密码正确
        {
            cout << "登录成功！" << endl;
            return true; //返回true表示登录成功
        }
        cout << "密码错误,请重新输入: ";
    }
    cout << "输入错误次数过多! " << endl;
    return false; //返回false表示登录失败
}

void del() //删除账户
{
    long long cardNum;
    cout << "请输入要删除的账户卡号: ";
    while (cin >> cardNum)
    {
        for (int i = 0; i < count; i++)
        {
            if (p[i]->getCardNum() == cardNum)
            {
                delete p[i]; //释放内存
                for (int j = i; j < count - 1; j++)
                {
                    p[j] = p[j + 1]; //将后面的账户前移
                }
                count--; //账户数量减一
                cout << "账户删除成功！" << endl;
                return;
            }
        }
        cout << "账户不存在,请重新输入卡号: ";
    }
}

void showAll() //显示所有账户信息
{
    cout << "所有账户信息:" << endl;
    for (int i = 0; i < count; i++)
    {
        p[i]->Show();
        cout << endl;
    }
}

void showAllRecord() //显示所有交易记录
{
    cout << "所有交易记录:" << endl;
    for (int i = 0; i < count; i++)
    {
        p[i]->ShowRecords();
    }
}

void amend() //修改账户信息
{
    long long cardNum;
    cout << "请输入要修改的账户卡号: ";
    while (cin >> cardNum)
    {
        for (int i = 0; i < count; i++)
        {
            if (p[i]->getCardNum() == cardNum)
            {
                if(Debit *d = dynamic_cast<Debit *>(p[i])) //借记卡
                {
                    cout << "1. 用户信息 | 2. 利率 " << endl;
                    cout << "请选择要修改的信息: ";
                    int choice;
                    while(cin >> choice)
                    {
                        if (choice == 1) //修改姓名
                        {
                            massage user = d->getUser(); //获取用户信息
                            user = user.amend(); //修改用户信息
                            d->setMassage(user); //设置新用户信息
                            return;
                        }
                        else if (choice == 2) //修改利率
                        {
                            double rate;
                            cout << "请输入新的利率: ";
                            cin >> rate;
                            d->setRate(rate); //设置新利率
                            cout << "利率修改成功！" << endl;
                            return;
                        }
                        else
                            cout << "输入错误,请重新输入: ";
                    }
                }
                else if (Credit *c = dynamic_cast<Credit *>(p[i])) //信用卡
                {
                    cout << "1. 用户信息 | 2. 最大贷款额度 | 3. 利率" << endl;
                    cout << "请选择要修改的信息: ";
                    int choice;
                    while(cin >> choice)
                    {
                        if (choice == 1) //修改姓名
                        {
                            massage user = c->getUser(); //获取用户信息
                            user = user.amend(); //修改用户信息
                            c->setMassage(user); //设置新用户信息
                            return;
                        }
                        else if (choice == 2) //修改最大贷款额度
                        {
                            double maxLoan;
                            cout << "请输入新的最大贷款额度: ";
                            cin >> maxLoan;
                            c->setMaxLoan(maxLoan); //设置新最大贷款额度
                            cout << "最大贷款额度修改成功！" << endl;
                            return;
                        }
                        else if (choice == 3) //修改利率
                        {
                            double rates;
                            cout << "请输入新的利率: ";
                            cin >> rates;
                            c->setRates(rates); //设置新利率
                            cout << "利率修改成功！" << endl;
                            return;
                        }
                        else
                            cout << "输入错误,请重新输入: ";
                    }
                }
            }
        }
        cout << "账户不存在,请重新输入卡号: ";
    }
}

