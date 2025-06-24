#include <iostream>
#include <ctime> //获取系统时间
#include <algorithm> //更改时间格式
#include "class.h"

string getTime() //获取当前时间
{
    time_t now = time(0);
    string timeStr = ctime(&now); //将时间转换为字符串
    timeStr = timeStr.substr(0, timeStr.length() - 1); //去掉换行符
    replace(timeStr.begin(), timeStr.end(), ' ', '_'); //将空格替换为下划线
    return timeStr; //返回时间字符串
}

bool Basics::checkPassword(const string &p) const //检查密码是否正确
{
    return password == p; //返回密码是否正确
}

void Basics::Show() const //显示账户信息
{
    user.Show(); //显示用户信息
    cout << "卡号: " << cardNum << endl;
    cout << "余额: " << balance << endl;
}

void Debit::Show() const //显示账户信息--借记卡
{
    Basics::Show();
    cout << "利率: " << rate << endl;
}

void Credit::Show() const //显示账户信息--信用卡
{
    Basics::Show();
    cout << "最大贷款: " << maxLoan << endl;
    cout << "利率: " << rates << endl;
    cout << "欠款: " << debt << endl;
}

void Basics::addRecord(const string &t, const string &ty, double am, long long an, double bal, double de) // 添加交易记录
{
    records.push_back(Record(t, ty, am, an, bal, de));
}

void Basics::ShowRecords() const //显示交易记录
{
    for (const auto &record : records)
    {
        record.Show();
    }
}

bool Basics::Deposit(double amt) //存款
{
    if (amt > 0)
    {
        balance += amt;
        string time = getTime(); //获取当前时间
        string type = "存款"; //交易类型
        addRecord(time, type, amt, cardNum, balance, -1); //添加交易记录
        return true;
    }
    else
    {        
        cout << "存款金额不能小于零！" << endl;
        return false;
    }
}

bool Credit::Deposit(double amt) //存款--信用卡
{
    if (amt > 0 && debt > 0) //有欠款
    {
        if (amt >= debt) //存款金额大于等于欠款
        {
            amt -= debt; //存款金额减去欠款
            debt = 0; //清空欠款
            Basics::Deposit(amt); //存入剩余金额
            string time = getTime(); //获取当前时间
            string type = "还款"; //交易类型
            addRecord(time, type, amt, getCardNum(), Balance(), debt); //添加交易记录
            return true;
        }
        else //存款金额小于欠款
        {
            debt -= amt; //减少欠款
            amt = 0; //存款金额清零
            string time = getTime(); //获取当前时间
            string type = "还款"; //交易类型
            addRecord(time, type, amt, getCardNum(), Balance(), debt); //添加交易记录
            return true;
        }
    }
    else if (amt > 0) //没有欠款
    {
        Basics::Deposit(amt); //存入金额
        string time = getTime(); //获取当前时间
        string type = "存款"; //交易类型
        addRecord(time, type, amt, getCardNum(), Balance(), debt); //添加交易记录
        return true;
    }
    else
    {
        cout << "存款金额不能小于零！" << endl;
        return false;
    }
}

bool Basics::Withdraw(double amt) //取款
{
    if (amt > 0 && amt <= balance)
    {
        balance -= amt;
        string time = getTime(); //获取当前时间
        string type = "取款"; //交易类型
        addRecord(time, type, amt, cardNum, balance, -1); //添加交易记录
        return true;
    }
    else if (amt <= 0)
    {
        cout << "取款金额不能小于零！" << endl;
        return false;
    }
    else
    {
        cout << "余额不足！" << endl;
        return false;
    }
}

bool Credit::Withdraw(double amt) //取款--信用卡
{
    double bal = Balance();
    if(amt<=bal) //卡内金额足够
    {
        Basics::Withdraw(amt);
        string time = getTime(); //获取当前时间
        string type = "取款"; //交易类型
        addRecord(time, type, amt, getCardNum(), Balance(), debt); //添加交易记录
        return true;
    }
    else if(amt <= bal + maxLoan - debt) //透支在额度内
    {
        double advance = amt - bal; //透支金额
        debt += advance * (1.0 + rates); //记录欠款
        cout << "透支金额: $" << advance << endl;
        cout << "透支利息: $" << advance * rates << endl;
        Basics::Deposit(advance); //存入透支金额
        Basics::Withdraw(amt); //取款
        string time = getTime(); //获取当前时间
        string type = "取款"; //交易类型
        addRecord(time, type, amt, getCardNum(), Balance(), debt); //添加交易记录
        return true;
    }
    else
    {
        cout << "取款金额超过信用额度,取款失败！" << endl;
        return false;
    }
}

