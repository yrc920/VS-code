#ifndef __CLASS_H__
#define __CLASS_H__

#include <string>
#include <vector>
#include "record.h"
#include "massage.h"

using namespace std;

class Basics //基类
{
    private:
        massage user; //用户信息
        long long cardNum; //卡号
        string password; //密码
        double balance; //余额   
        vector<Record> records; //交易记录

    public:
        Basics(massage u = massage(), long long an = -1, string p = "123456", double bal = 0.0) : user(u), cardNum(an), password(p), balance(bal) {} //使用用户信息类的默认构造函数
        massage getUser() const { return user; } //获取用户信息
        long long getCardNum() const { return cardNum; } //获取卡号
        string getPassword() const { return password; } //获取密码
        double Balance() const { return balance; } //获取余额

        void setPassword(const string &p) { password = p; } //设置密码
        bool checkPassword(const string &p) const; //检查密码是否正确

        virtual bool Deposit(double amt); //存款
        virtual bool Withdraw(double amt); //取款

        void addRecord(const string &t, const string &ty, double am, long long an, double bal, double de); //添加交易记录
        void ShowRecords() const; //显示交易记录
        const vector<Record> &getRecords() const { return records; } //获取交易记录

        void setMassage(const massage &u) { user = u; } //设置用户信息
        
        virtual void Show() const; //显示账户信息
        virtual ~Basics() {}
};

class Debit : public Basics //借记卡
{
    private:
        double rate; //利率

    public:
        Debit(massage u = massage(), long long an = -1, string p = "123456", double bal = 0.0, double r = 0.5) : Basics(u, an, p, bal), rate(r) {}
        Debit(const Basics &ba, double r = 0.5) : Basics(ba), rate(r) {}

        double getRate() const { return rate; } //获取利率
        void setRate(double r) { rate = r; } //设置利率
        virtual void Show() const; //显示账户信息
};

class Credit : public Basics //信用卡
{
    private:
        double maxLoan; //最大贷款
        double rates; //利率
        double debt; //欠款

    public:
        Credit(massage u = massage(), long long an = -1, string p = "123456", double bal = 0.0, double ml = 0.0, double r = 0.5) : Basics(u, an, p, bal), maxLoan(ml), rates(r), debt(0.0) {}
        Credit(const Basics &ba, double ml = 0.0, double r = 0.5) : Basics(ba), maxLoan(ml), rates(r), debt(0.0) {}
        
        void setDebt(double d) { debt = d; } //设置欠款
        virtual bool Deposit(double amt); //存款
        virtual bool Withdraw(double amt); //取款
        virtual void Show() const; //显示账户信息
        
        void setMaxLoan(double ml) { maxLoan = ml; } //设置最大贷款
        void setRates(double r) { rates = r; } //设置利率

        double getMaxLoan() const { return maxLoan; } //获取最大贷款
        double getRates() const { return rates; } //获取利率
        double getDebt() const { return debt; } //获取欠款
};

#endif

