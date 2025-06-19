#ifndef __RECORD_H__
#define __RECORD_H__

#include <string>

using namespace std;

class Record
{
    private:
        string times; //交易时间
        string type; //交易类型
        double amount; //交易金额
        long long cardNum; //卡号
        double balance; //余额
        double debt; //欠款(信用卡)
        
    public:
        Record(const string &t = "Nullbody", const string &ty = "Nullbody", double am = 0.0, long long an = -1, double bal = 0.0, double de = -1.0) : times(t), type(ty), amount(am), cardNum(an), balance(bal), debt(de) {}

        string toString() const; //将记录转换为字符串
        void Show() const; //显示记录
};

#endif

