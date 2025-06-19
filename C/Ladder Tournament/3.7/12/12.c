#include<stdio.h>
int main()
{
    int n,a[1001],b[1001];//记录总信息
    long long num[1001];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&num[i]);
        scanf("%d%d",&a[i],&b[i]);
    }
    int m,c[1001];//记录要查找的信息
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&c[i]);
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(c[i]==a[j])
            {
                printf("%lld %d\n",num[j],b[j]);
                break;
            }
        }
    }
    return 0;
}

