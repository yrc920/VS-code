#include<stdio.h>
int main()
{
    char a[1000][6];
    int i;
    int c = 0;
    for (i = 0; i<1000; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            scanf("%c", &a[i][j]);
            if (a[i][j] == ' ')
            {
                break;
            }
            if (a[i][j] == '\n')
            {
                c = 1;
                break;
            }
        }
        if(c==1)
            break;
    }    
    for (int q = 0; q < i; q++)
    {
        if (a[q][0] == '2' &&a[q][1] == '5' &&a[q][2] == '0')
        {
            printf("%d", q + 1);
            break;
        }    
    }
    return 0;
}

