#include<stdio.h>
#include<string.h>
int main()
{
    int n,f=0;
    char a[100][19];
    int b[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s",a[i]);
    for(int i=0;i<n;i++)
    {
        int sum=0,z;
        char m;
        for(int j=0;j<17;j++)
        {
            int x=(int)(a[i][j]-'0')*b[i];
            sum+=x;
        }
        z=sum%11;
        if(z==0) m='1';
        if(z==1) m='0';
        if(z==2) m='X';
        if(z==3) m='9';
        if(z==4) m='8';
        if(z==5) m='7';
        if(z==6) m='6';
        if(z==7) m='5';
        if(z==8) m='4';
        if(z==9) m='3';
        if(z==10) m='2';
        if(a[i][17]!=m)
        {
            f=1;
            printf("%s\n",a[i]);
        }
    }
    if(f==0) printf("All passed");
    return 0;
}

