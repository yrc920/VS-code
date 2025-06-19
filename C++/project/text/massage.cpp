#include "massage.h"

ostream &operator<<(ostream &os, const massage &m) //重载输出运算符
{
    os << m.name << " " << m.phone << " " << m.address;
    return os; //用于文件操作
}

istream &operator>>(istream &is, massage &m) //重载输入运算符
{
    is >> m.name >> m.phone >> m.address;
    return is; //用于文件操作
}

void massage::Show() const //显示信息
{
    cout << "姓名: " << name << endl;
    cout << "手机号: " << phone << endl;
    cout << "地址: " << address << endl;
}

massage massage::build() //创建用户信息时使用
{
    string name;
    long long phone;
    string address;
    cout << "请输入姓名: ";
    while (cin >> name)
    {
        if (name.length() > 0 && name.length() <= 20)
            break;
        cout << "姓名长度不合法,请重新输入：";
    }
    cout << "请输入手机号: ";
    while (cin >> phone)
    {
        if (phone > 0 && phone < 10000000000000) //手机号合法性检查
            break;
        cout << "手机号不合法,请重新输入：";
    }
    cout << "请输入地址: ";
    while (cin >> address)
    {
        if (address.length() > 0 && address.length() <= 50)
            break;
        cout << "地址长度不合法,请重新输入：";
    }
    return massage(name, phone, address);
}

massage massage::amend() //修改用户信息时使用
{
    cout << "1. 姓名 | 2. 手机号 | 3. 地址" << endl;
    cout << "请选择要修改的信息: ";
    int choice;
    while (cin >> choice)
    {
        if (choice == 1) //修改姓名
        {
            string name;
            cout << "请输入新的姓名: ";
            while (cin >> name)
            {
                if (name.length() > 0 && name.length() <= 20)
                    break;
                cout << "姓名长度不合法,请重新输入：";
            }
            this->name = name; //设置新姓名
            cout << "姓名修改成功！" << endl;
            return *this;
        }
        else if (choice == 2) //修改手机号
        {
            long long phone;
            cout << "请输入新的手机号: ";
            while (cin >> phone)
            {
                if (phone > 0 && phone < 10000000000000) //手机号合法性检查
                    break;
                cout << "手机号不合法,请重新输入：";
            }
            this->phone = phone; //设置新手机号
            cout << "手机号修改成功！" << endl;
            return *this;
        }
        else if (choice == 3) //修改地址
        {
            string address;
            cout << "请输入新的地址: ";
            while (cin >> address)
            {
                if (address.length() > 0 && address.length() <= 50)
                    break;
                cout << "地址长度不合法,请重新输入：";
            }
            this->address = address; //设置新地址
            cout << "地址修改成功！" << endl;
            return *this;
        }
        else
            cout << "输入错误,请重新输入: ";
    }
    return *this; //返回修改后的对象
}

