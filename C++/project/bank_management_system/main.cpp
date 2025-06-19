#include <iostream>
#include "fun.h"

using namespace std;

int main()
{
    initialize(); //初始化系统
    while(1)
    {
        cout << "----------------------------" << endl;
        cout << "| 欢迎使用银行管理系统！    |" << endl;
        cout << "| 请选择您要办理的业务：    |" << endl;
        cout << "| 1. 创建账户               |" << endl;
        cout << "| 2. 存款                   |" << endl;
        cout << "| 3. 取款                   |" << endl;
        cout << "| 4. 显示账户信息           |" << endl;
        cout << "| 5. 显示交易记录           |" << endl;
        cout << "| 0. 退出                   |" << endl;
        cout << "----------------------------" << endl;
        cout << "请输入您的选择：";
        int choice;
        while(cin >> choice)
        {
            if (cin.fail()) //输入错误
            {
                cin.clear(); //清除错误标志
                while(cin.get() != '\n'); //清除输入缓冲区
                cout << "无效的输入，请重新输入：";
            }
            else if (choice < 0 || choice > 5) //输入范围错误
            {
                cout << "无效的选择，请重新输入：";
            }
            else
                break; //输入正确，跳出循环
        }
        switch (choice)
        {
            case 1:
                build(); //创建账户
                break;
            case 2:
                deposit(); //存款
                break;
            case 3:
                withdraw(); //取款
                break;
            case 4:
                show(); //显示账户信息
                break;
            case 5:
                showRecord(); //显示交易记录
                break;
            case 0:
                cout << "感谢使用银行管理系统！" << endl;
                save(); //保存账户信息
                return 0; //退出系统
        }
    }
    return 0;
}

