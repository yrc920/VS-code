#include<stdio.h>
int main()
{
    int a,b,n;
    int b0=0,a0=0;
    scanf("%d%d",&a,&b);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a1,a2,b1,b2;
        scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
        if(a1+b1==a2 && a1+b1!=b2)
        {
            a--;
            a0++;
        }
        else if(a1+b1!=a2 && a1+b1==b2)
        {
            b--;
            b0++;
        }
        if(a<0)
        {
            printf("A\n%d\n",b0);
            break;
        }
        else if(b<0)
        {
            printf("B\n%d\n",a0);
            break;
        }
    }
    return 0;
}

