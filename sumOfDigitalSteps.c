// 数字阶数求和
#include <stdio.h>
int main()
{
    // 数位是bit,最大有ns位
    int bit, ns;
    scanf("%d %d", &bit, &ns);

    // 存放和的每一位
    int arr[150];

    // 低位进位
    int carry = 0;

    // 从个位开始计算
    int pos = 0;

    for (int i = 0; i <= pos; i++)
    {
        // 对a+aa+aaa+a...a(n个a) =
        // a * n + a * (n - 1) + ...+ a
        int base = ns - pos >= 0 ? ns - pos : 0;

        // 没有进位之前低位的和
        arr[i] = bit * base + carry;
        // 向高位进位
        carry = arr[i] / 10;
        // 向高位进位后的低位值
        arr[i] = arr[i] % 10;
        // 当前处理位加1
        // 只在两种情况下加1:
        // 1. 当前正处理第0 ~ n - 2之间的部分
        // 2. 当前处理n - 1位前面的部分并且进位不为0
        if (i < ns - 1 || (i >= ns - 1 && carry != 0))
        {
            pos++;
        }
    }

    // 处理时从低位到高位,输出时反向
    for (int i = pos; i >= 0; i--)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
}