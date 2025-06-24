#include <iostream>
#include "fun.h"

using namespace std;

int main()
{
    initialize(); //初始化系统
    while(1)
    {
        int choice = begin(); //显示菜单
        switch (choice)
        {
            case 1: //用户登录
            {
                int index = enter1(); //登录
                if (index == -1) //登录失败
                {
                    cout << "登录失败,请重新选择操作" << endl;
                        break; //跳出循环
                }
                while(1)
                {
                    choice = majors(); //选择业务
                    switch (choice)
                    {
                        case 1: //存款
                            deposit(index);
                            break;
                        case 2: //取款
                            withdraw(index);
                            break;
                        case 3: //查询账户信息
                            show(index);
                            break;
                        case 4: //显示交易记录
                            showRecord(index);
                            break;
                        case 5: //修改密码
                            amendPassword(index);
                            break;
                        case 0: //退出系统
                            save(); //保存账户信息
                            cout << "正在退出登录! " << endl;
                            break;
                    }
                    if (choice == 0) //退出用户模式
                        break; //跳出循环
                }
            } //括号括起防止变量作用域混淆
                break;
            case 2: //管理员模式
                if (!enter2()) //登录失败
                {
                    cout << "登录失败,请重新选择操作" << endl;
                    break; //跳出循环
                }
                while(1)
                {
                    choice = regulate(); //选择管理员操作
                    switch (choice)
                    {
                        case 1: //添加账户
                            build();
                            break;
                        case 2: //删除账户
                            del();
                            break;
                        case 3: //显示所有账户信息
                            showAll();
                            break;
                        case 4: //显示所有交易记录
                            showAllRecord();
                            break;
                        case 5: //修改账户信息
                            amend();
                            break;    
                        case 0: //退出系统
                            save(); //保存账户信息
                            cout << "正在退出管理员模式! " << endl;
                            break; //跳出循环
                    }
                    if (choice == 0) //退出管理员模式
                        break; //跳出循环
                }
                break;
            case 0: //退出系统
                save(); //保存账户信息
                cleanup(); //清理内存
                cout << "感谢使用银行管理系统！" << endl;
                return 0;
        }
    }
    return 0;
}

