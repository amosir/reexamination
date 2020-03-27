#include <stdio.h>
#define ROWS 100
int main()
{
    // 矩阵维数
    int n;
    int matrix[ROWS][ROWS];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                printf("No!");
                return 0;
            }
        }
    }

    printf("Yes!");
    return 0;
}