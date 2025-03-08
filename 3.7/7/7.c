#include<stdio.h>
int main()
{
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    for(int i=0;i<q;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        if(x==0)
        {
            n--;
        }
        else
        {
            m--;
        }
    }
    printf("%d\n",n*m);
    return 0;
}

