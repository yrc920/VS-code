#include<stdio.h>
#include"fun.h"
int main()
{
    int a;
    while(1)
    {
        printf("*********************************\n");
        printf("*创建学生表请输1 退出请输0      *\n");
        printf("*插入数据请输2   删除数据请输3  *\n");
        printf("*输出表单请输4   个数统计请输5  *\n");
        printf("*按姓名排序请输6 按学号排序请输7*\n");
        printf("*按姓名查找请输8 按学号查找请输9*\n");
        printf("*********************************\n");
        int b=scanf("%d",&a);
        if(b==0)
        {
            while(getchar()!='\n');//清空缓冲区
            printf("请输入正确的数字\n\n");
            continue;
        }
        switch(a)
        {
            case 0: return 0;
            case 1: found();break;
            case 2: insert();printf("完成\n");break;
            case 3: del();break;
            case 4: output();break;
            case 5: count();break;
            case 6: sort1();break;
            case 7: sort2();break;
            case 8: find1();break;
            case 9: find2();break;
            default: printf("请输入正确的数字\n");break;
        }
        printf("\n");
    }
    return 0;
}

