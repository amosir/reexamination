#include <stdio.h>
#define SIZE 1000
int main()
{
    int cnt;
    while (scanf("%d", &cnt) != EOF && cnt != 0)
    {

        // 栈
        int stack[SIZE];
        int top = -1;

        // 吸收换行符
        getchar();
        for (int i = 0; i < cnt; i++)
        {
            // 操作
            char ch = getchar();
            getchar();
            if (ch == 'P')
            {
                int temp;
                scanf(" %d", &temp);
                stack[++top] = temp;
                getchar();
            }
            else if (ch == 'O')
            {
                if (top >= 0)
                {
                    top--;
                }
            }
            else if (ch == 'A')
            {
                if (top >= 0)
                {
                    printf("%d\n", stack[top]);
                }
                else
                {
                    printf("E\n");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
