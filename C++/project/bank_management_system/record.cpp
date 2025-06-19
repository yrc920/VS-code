#include <iostream>
#include "record.h"

string Record::toString() const //将记录转换为字符串
{
    string result = times + " " + type + " " + to_string(amount) + " " + to_string(cardNum) + " " + to_string(balance) + " " + to_string(debt);
    return result;
}

void Record::Show() const //显示记录
{
    cout << "时间: " << times
         << " | 交易类型: " << type
         << " | 交易金额: " << amount
         << " | 卡号: " << cardNum
         << " | 余额: " << balance;
    if (debt != -1)
        cout << " | 欠款: " << debt;
    cout << endl;
}

