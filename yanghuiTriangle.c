#include <stdio.h>
#define MAX 15
// 计算杨辉三角形
void YHTriangle(int a[][15], int n);
// 打印杨辉三角形
void PrintYHTriangle(int a[][15], int n);

int main()
{
    int a[15][15] = {0};
    printf("Input n(n < 15):\n");
    int n;
    scanf("%d", &n);
    YHTriangle(a, n);
    PrintYHTriangle(a, n);
    return 0;
}

void YHTriangle(int a[][15], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || i == j)
            {
                a[i][j] = 1;
            }
            else
            {
                a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
            }
        }
    }
}
void PrintYHTriangle(int a[][15], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
}
