#include<stdio.h>
int main(){
    int matrix_1[2][3], matrix_2[3][2], matrix_3[2][2];
    printf("请输入第一个矩阵(2 * 3)\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3;j++){
            scanf("%d",&matrix_1[i][j]);
        }
    }
    printf("请输入第二个矩阵(3 * 2)\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2;j++){
            scanf("%d",&matrix_2[i][j]);
        }
    }
    printf("结果是\n");

    for (int i = 0; i < 2;i++){
        for (int j = 0; j < 2;j++){
            int temp = 0;
            for (int k = 0; k < 3; k++)
            {
                temp += matrix_1[i][k] * matrix_2[k][j];
            }
            matrix_3[i][j] = temp;
        }
    }

    for (int i = 0; i < 2;i++){
        for (int j = 0; j < 2;j++){
            printf("%d\t",matrix_3[i][j]);
        }
        printf("\n");
    }
    return 0;
}