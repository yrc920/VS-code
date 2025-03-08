#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    if(n<=5) n+=2;
    else n=n-5;
    printf("%d", n);
    return 0;
}

