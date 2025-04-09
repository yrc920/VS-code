#include<stdio.h>
int main()
{
    int x, y;
    int a;
    scanf("%d%d", &x, &y);
    a = 5000 - 50 * (100-x+y);
    printf("%d", a);
    return 0;
}

