#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    char a[100][6];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            scanf("%c", &a[i][j]);
        }
        getchar();
    }
    for (int i = 0; i < n; i++)
    {
        int m, n;
        m = (int)a[i][0] + (int)a[i][1] + (int)a[i][2];
        n = (int)a[i][3] + (int)a[i][4] + (int)a[i][5];
        if (m == n)
            printf("You are lucky!");
        else
            printf("Wish you good luck.");
        if(i != n - 1)
            printf("\n");
    }
    return 0;
}

