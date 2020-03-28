#include <stdio.h>
#define MAX_LEN 21
#define MAX_CNT 100
int main()
{
    char stack[MAX_CNT][MAX_LEN];
    // 栈顶
    int top = -1;
    int cnt;
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++)
    {
        getchar();
        scanf("%s", stack[++top]);
        // 从栈顶往下输出
        for (int j = top; j >= 0 && j >= top - 3; j--)
        {
            printf("%d=%s ", top - j + 1, stack[j]);
        }
        printf("\n");
    }
    return 0;
}