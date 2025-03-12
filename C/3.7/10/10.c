#include<stdio.h>
int main()
{
    int n;
    double a[100];//记录单价
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lf",&a[i]);
    int b[100]={0};//记录碗数
    while(1)
    {
        int m,n;
        scanf("%d %d",&m,&n);
        if(m==0 && n==0) break;
        else b[m-1]+=n;
    }
    double sum=0;
    for(int i=0;i<n;i++)
    {
        printf("%d\n",b[i]);
        sum+=a[i]*b[i];
    }
    printf("%.2f\n",sum);
    return 0;
}

