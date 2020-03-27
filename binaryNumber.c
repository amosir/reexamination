#include <stdio.h>
#define MAX_LEN 20
int main()
{
    unsigned int num;
    scanf("%d", &num);

    // 保存二进制数
    int bits[MAX_LEN];
    int pos = 0;
    while (num != 0)
    {
        // 求末位
        bits[pos++] = (num & 1);
        // 右移一位
        num = num >> 1;
    }
    // 从高位往低位输出
    for (int i = pos - 1; i >= 0; i--)
    {
        printf("%d", bits[i]);
    }
    printf("\n");
    return 0;
}