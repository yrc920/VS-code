#include <stdio.h>
#include <string.h>

#define MAX_LEN 30000

char current_str[MAX_LEN] = {0};
char clip_str[MAX_LEN] = {0};

void cut(int start, int end)
{
    int a = start - 1;
    int b = end - 1;
    int current_len = strlen(current_str);

    // 复制剪切的内容到剪贴板
    strncpy(clip_str, current_str + a, b - a + 1);
    clip_str[b - a + 1] = '\0';

    // 构造剪切后的字符串
    char temp[MAX_LEN] = {0};
    strncpy(temp, current_str, a);
    temp[a] = '\0';
    if (b + 1 < current_len)
    {
        strcat(temp, current_str + b + 1);
    }
    strcpy(current_str, temp);
}

void paste(char *s1, char *s2)
{
    int m = strlen(s1);
    int n = strlen(s2);
    int current_len = strlen(current_str);
    int found = -1;

    // 查找插入位置
    for (int i = 0; i <= current_len - m - n; i++)
    {
        if (strncmp(current_str + i, s1, m) == 0 &&
            strncmp(current_str + i + m, s2, n) == 0)
        {
            found = i;
            break;
        }
    }

    char new_str[MAX_LEN] = {0};
    if (found != -1)
    {
        // 插入到找到的位置
        strncpy(new_str, current_str, found + m);
        new_str[found + m] = '\0';
        strcat(new_str, clip_str);
        strcat(new_str, current_str + found + m);
    }
    else
    {
        // 追加到末尾
        strcpy(new_str, current_str);
        strcat(new_str, clip_str);
    }

    strcpy(current_str, new_str);
    // 清空剪贴板
    clip_str[0] = '\0';
}

int main()
{
    scanf("%s", current_str);
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int start, end;
        char s1[6], s2[6];
        scanf("%d %d %s %s", &start, &end, s1, s2);
        cut(start, end);
        paste(s1, s2);
    }

    printf("%s\n", current_str);
    return 0;
}