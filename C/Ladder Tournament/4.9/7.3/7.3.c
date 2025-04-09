#include<stdio.h>
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    if (a > 0 &&b > 0)
    {
        printf("%d %d\n", a > b ? a : b, a + b);
        printf("^_^");
    }
    else if (a > 0 &&b < 0)
    {
        if(a > -b)
        {
            printf("%d %d\n", a, a + b);
        }    
        else
        {
            printf("%d %d\n", a, 0);
        }
        printf("T_T");
    }
    else if (a < 0 &&b > 0)
    {
        if (b > -a)
        {
            printf("%d %d\n", b, b + a);
        }
        else 
        {
            printf("%d %d\n", b, 0);
        }
        printf("T_T");
    }
    else
    {
        printf("0 0");
        printf("\n");
        printf("-_-");
    }
    return 0;
}

