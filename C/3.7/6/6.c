#include<stdio.h>
int main()
{
    int a[6],n;
    for(int i=0;i<6;i++)
        scanf("%d",&a[i]);
    scanf("%d",&n);
    int num[7][5];
    for(int i=1;i<7;i++)
    {
        int count[7]={0};//标记是否使用过
        count[i]=1;
        for( int j=0;j<5;j++)
        {
            int max=0;
            for(int k=6;k>0;k--)//找到最大的未使用过的数
            {
                if(!count[k])
                {
                    max=k;
                    break;
                }
            }
            num[i][j]=max;
            count[max]=1;
        }
    }
    for(int i=0;i<6;i++)
    {
        printf("%d",num[a[i]][n-1]);
        if(i!=5) printf(" ");
    }
    return 0;
}

