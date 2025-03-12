#include<stdio.h>
#include<string.h>
int main()
{
    char a[52];
    double n=1.0;//记录倍数
    scanf("%s",a);
    int i=strlen(a);//记录总数
    if(a[0]=='-')
    {
        i--;
        n*=1.5;
    }
    if(a[strlen(a)-1]=='0'||a[strlen(a)-1]=='2'||a[strlen(a)-1]=='4'||a[strlen(a)-1]=='6'||a[strlen(a)-1]=='8') n*=2.0;
    int m=0;//记录2的个数
    for(int j=0;a[j]!='\0';j++)
    {
        if(a[j]=='2') m++;
    }
    printf("%.2lf%%",(m*n)/i*100.0);
    return 0;
}

