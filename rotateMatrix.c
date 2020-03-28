#include<stdio.h>
#define SIZE 9
// 判断矩阵是否相等
int isSame(int matrix1[][SIZE],int matrix2[][SIZE],int rows){
    for(int i = 0;i < rows;i++){
        for(int j = 0;j < rows;j++){
            if(matrix1[i][j]!=matrix2[i][j]){
                return 0;
            }
        }
    }
    return 1;
}
void swap(int *num1,int *num2){
    *num1 = *num1 ^ *num2;
    *num2 = *num2 ^ *num1;
    *num1 = *num1 ^ *num2;
}
// 顺时针翻转90度
void rotate90D(int matrix[][SIZE],int rows){
    /** 
     *  1 2 3   7 8 9   7 4 1
     *  4 5 6   4 5 6   8 5 2
     *  7 8 9   1 2 3   9 6 3
     */
    // 先上下翻转
    int top = 0,bottom = rows - 1;
    while(top < bottom){
        for(int i = 0;i < rows;i++){
            swap(&matrix[top][i],&matrix[bottom][i]);
        }
        top++;
        bottom--;
    }

    // 再沿对角线翻转
    for(int i = 0;i < rows;i++){
        for(int j= 0;j < i;j++){
            swap(&matrix[i][j],&matrix[j][i]);
        }
    }
}
int main(){
    int initialMatrix[SIZE][SIZE],rotatedMatrix[SIZE][SIZE];
    int cnt;
    scanf("%d",&cnt);
    for(int i = 0;i < cnt;i++){
        for(int j = 0;j < cnt;j++){
            scanf("%d",&initialMatrix[i][j]);
        }
    }
    for(int i = 0;i < cnt;i++){
        for(int j = 0;j < cnt;j++){
            scanf("%d",&rotatedMatrix[i][j]);
        }
    }

    int degree = 0;
    while(degree < 360 && !isSame(initialMatrix,rotatedMatrix,cnt)){
        rotate90D(initialMatrix,cnt);
        degree += 90;
    }
    if(degree >= 360){
        printf("-1\n");
    }else{
        printf("%d\n",degree);
    }
    return 0;
}