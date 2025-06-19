#include <iostream>

using namespace std;

int choose(int n) //避免错误输入
{
    int choice;
    while (cin >> choice)
    {
        if (cin.fail()) //输入错误
        {
            cin.clear(); //清除错误标志
            while (cin.get() != '\n'); //清除输入缓冲区
            cout << "无效的输入，请重新输入：";
        }
        else if (choice < 0 || choice > n) //输入范围错误
        {
            cout << "无效的选择，请重新输入：";
        }
        else
            break; //输入正确,跳出循环
    }
    return choice;
}

int begin() //显示主菜单
{
    cout << "----------------------------" << endl;
    cout << "| 欢迎使用银行管理系统！    |" << endl;
    cout << "| 1. 用户登录               |" << endl;
    cout << "| 2. 管理员模式             |" << endl;
    cout << "| 0. 退出                   |" << endl;
    cout << "----------------------------" << endl;
    cout << "请输入您的选择：";
    return choose(2); //返回用户选择
}

int majors() //显示用户菜单
{
    cout << "----------------------------" << endl;
    cout << "| 请选择您要办理的业务      |" << endl;
    cout << "| 1. 存款                   |" << endl;
    cout << "| 2. 取款                   |" << endl;
    cout << "| 3. 查询账户信息           |" << endl;
    cout << "| 4. 显示交易记录           |" << endl;
    cout << "| 5. 修改密码               |" << endl;
    cout << "| 0. 退出                   |" << endl;
    cout << "----------------------------" << endl;
    cout << "请输入您的选择：";
    return choose(5); //返回用户选择
}

int regulate() //显示管理员菜单
{
    cout << "----------------------------" << endl;
    cout << "| 欢迎使用管理员模式！      |" << endl;
    cout << "| 1. 创建账户               |" << endl;
    cout << "| 2. 删除账户               |" << endl;
    cout << "| 3. 显示所有账户信息       |" << endl;
    cout << "| 4. 显示所有交易记录       |" << endl;
    cout << "| 5. 修改账户信息           |" << endl;
    cout << "| 0. 退出                   |" << endl;
    cout << "----------------------------" << endl;
    cout << "请输入您的选择：";
    return choose(5); //返回管理员选择
}

