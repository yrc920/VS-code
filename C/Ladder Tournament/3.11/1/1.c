#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000];
    scanf("%s",a);
    int n=strlen(a);
    for(int i=0;i<n;i++)
    {
        if(a[i]=='-') printf("fu");
        if(a[i]=='0') printf("ling");
        if(a[i]=='1') printf("yi");
        if(a[i]=='2') printf("er");
        if(a[i]=='3') printf("san");
        if(a[i]=='4') printf("si");
        if(a[i]=='5') printf("wu");
        if(a[i]=='6') printf("liu");
        if(a[i]=='7') printf("qi");
        if(a[i]=='8') printf("ba");
        if(a[i]=='9') printf("jiu");
        if(i!=n-1) printf(" ");
    }
    return 0;
}

