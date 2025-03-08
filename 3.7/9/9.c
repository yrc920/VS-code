#include<stdio.h>
int main()
{
    int n,color[101],k;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&color[i]);
    scanf("%d",&k);
    while(k--)
    {
        int guess[101];
        int a=0,b=0;
        for(int j=0;j<n;j++)
            scanf("%d",&guess[j]);
        for(int j=0;j<n;j++)
        {
            if(guess[j]==0) continue;
            if(guess[j]==color[j]) a=1;
            else b=1;
        }
        if(b) printf("Ai Ya\n");
        else if(a) printf("Da Jiang!!!\n");
        else printf("Ai Ya\n");
    }
    return 0;
}

