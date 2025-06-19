#include<stdio.h>
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    int p;
    scanf("%d", &p);
    for (int i = 0; i < p; i++)
    {
        int b[m + 1];
        int l = 0;
        for (int c = 0; c <= m; c++)
            b[c] = 0;
        for (int j = 0; j < n; j++)
        {
            int x = 0;
            scanf("%d", &x);
            if (x == 0)
                break;
            b[a[x]]++;
        }
        for (int j = 1; j <= m; j++)
        {
            
            if (b[j] == 0)
            {
                continue;
            }
            else
            {
                if (l == 1)
                {
                    printf(" ");
                }
                l = 1;
                printf("B%d-%d", j, b[j]);
            }
        }
        if(i != p - 1)
        {
            printf("\n");
        }
    }
}

