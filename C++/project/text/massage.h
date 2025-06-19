#ifndef __MASSAGE_H__
#define __MASSAGE_H__

#include <iostream>
#include <string>

using namespace std;

class massage
{
    private:
        string name; //姓名
        long long phone; //手机号
        string address; //地址
    public:
        massage(const string &n = "Nullbody", long long p = -1, const string &a = "Nullbody") : name(n), phone(p), address(a) {}
        massage(const massage &m) : name(m.name), phone(m.phone), address(m.address) {} //拷贝构造函数

        friend ostream &operator<<(ostream &os, const massage &m); //用于文件操作
        friend istream &operator>>(istream &is, massage &m); //用于文件操作

        void Show() const; //显示用户信息
        massage build(); //创建用户信息时使用
        massage amend(); //修改用户信息时使用
};

#endif

