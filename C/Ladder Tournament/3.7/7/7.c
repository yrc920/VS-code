#include<stdio.h>
int main()
{
    int n,m,q;
    int a[100001]={0};
    int b[100001]={0};
    int c=0,d=0;
    scanf("%d %d %d",&n,&m,&q);
    while(q--)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        if(x==0&&!a[y])
        {
            a[y]=1;
            c++;
        }
        else if(x==1&&!b[y])
        {
            b[y]=1;
            d++;
        }
    }
    printf("%d",(n-c)*(m-d));
    return 0;
}

