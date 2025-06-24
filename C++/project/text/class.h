#ifndef CLASS_H__
#define CLASS_H__

#include <iostream>
#include <string>
#include <vector>
#include "record.h"

using namespace std;

class Basics //基类
{
    private:
        string name; //姓名
        long long cardNum; //卡号
        double balance; //余额   
        vector<Record> records; //交易记录

    public:
        Basics(const string &s = "Nullbody", long long an = -1, double bal = 0.0) : name(s), cardNum(an), balance(bal) {}
        string getName() const { return name; } //获取姓名
        long long getCardNum() const { return cardNum; } //获取卡号
        double Balance() const { return balance; } //显示余额

        bool Deposit(double amt); //存款
        virtual bool Withdraw(double amt); //取款

        void addRecord(const string &t, const string &ty, double am, long long an, double bal, double de); //添加交易记录
        void ShowRecords() const; //显示交易记录
        const vector<Record> &getRecords() const { return records; } //获取交易记录
        
        virtual void Show() const; //显示账户信息
        virtual ~Basics() {}
};

class Debit : public Basics //借记卡
{
    private:
        double rate; //利率

    public:
        Debit(const string &s = "Nullbody", long long an = -1, double bal = 0.0, double r = 0.0) : Basics(s, an, bal), rate(r) {}
        Debit(const Basics &ba, double r = 0.0) : Basics(ba), rate(r) {}

        double getRate() const { return rate; } //获取利率
        virtual void Show() const; //显示账户信息
};

class Credit : public Basics //信用卡
{
    private:
        double maxLoan; //最大贷款
        double rates; //利率
        double debt; //欠款

    public:
        Credit(const string &s = "Nullbody", long long an = -1, double bal = 0.0, double ml = 500.0, double r = 0.11125) : Basics(s, an, bal), maxLoan(ml), rates(r), debt(0.0) {}
        Credit(const Basics &ba, double ml = 500.0, double r = 0.11125) : Basics(ba), maxLoan(ml), rates(r), debt(0.0) {}
        
        void setDebt(double d) { debt = d; } //设置欠款
        virtual bool Deposit(double amt); //存款
        virtual bool Withdraw(double amt); //取款
        virtual void Show() const; //显示账户信息

        double getMaxLoan() const { return maxLoan; } //获取最大贷款
        double getRates() const { return rates; } //获取利率
        double getDebt() const { return debt; } //获取欠款
};



#endif

