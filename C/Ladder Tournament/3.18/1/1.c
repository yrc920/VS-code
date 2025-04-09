#include<stdio.h>
int main()
{
    int n,b[1000],c[1000];
    long long a[1000];
    scanf("%d", &n);
    for (int i = 0; i < n;i++)
        scanf("%lld%d%d", &a[i], &b[i], &c[i]);
    int m, d[1000];
    scanf("%d", &m);
    for (int i = 0; i < m;i++)
        scanf("%d", &d[i]);
    for (int i = 0; i < m;i++)
    {
        for (int j = 0; j < n;j++)
        {
            if(d[i]==b[j])
            {
                printf("%lld %d\n", a[j], c[j]);
                break;
            }
        }
    }
    return 0;
}

