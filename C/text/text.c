#include <stdio.h>
int main()
{
    int heads, legs;
    printf("请输入头数和腿数：");
    scanf("%d %d", &heads, &legs);
    if (heads <= 0 || legs <= 0)
    {
        printf("输入错误\n");
        return 1;
    }
    if (legs % 2 != 0 || legs < 2 * heads || legs > 4 * heads)
    {
        printf("无解\n");
        return 0;
    }
    int rabbits = (legs - 2 * heads) / 2;
    int chickens = heads - rabbits;
    if (rabbits >= 0 && chickens >= 0)
        printf("鸡有%d只, 兔有%d只\n", chickens, rabbits);
    else
        printf("无解\n");
    return 0;
}

