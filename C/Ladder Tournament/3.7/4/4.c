#include<stdio.h>
int main()
{
    char a[50][11];
    int n=0;
    for(int i=0;i<50;i++)
    {
        scanf("%s",a[i]);
        if(a[i][0] == '.')
            break;
        n++;
    }
    if(n>=14)
    {
        printf("%s and %s are inviting you to dinner...",a[1],a[13]);
    }
    else if(n>=2)
    {
        printf("%s is the only one for you...",a[1]);
    }
    else
    {
        printf("Momo... No one is for you ...");
    }
    return 0;
}

