#include<stdio.h>
int main()
{
    int a,b,n;
    scanf("%d %d %d",&a,&b,&n);
    int c[1000];
    c[0]=a;c[1]=b;
    if(n<2)
    {
        for(int i=0;i<n;i++)
        {
            printf("%d",c[i]);
            if(i!=n-1) printf(" ");
        }
        return 0;
    }
    int count=2;
    for(int i=0;i<n;i++)
    {
        int m=c[i]*c[i+1];
        if(m>=10)
        {
            c[count]=m/10;
            c[count+1]=m%10;
            count+=2;
            if(count>=n) break;
        }
        else
        {
            c[count]=m;
            count++;
            if(count>=n) break;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d",c[i]);
        if(i!=n-1) printf(" ");
    }
    return 0;
}

