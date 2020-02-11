// 数字阶数求和
#include <stdio.h>
int main()
{
    int n, a;

    int arr[200] = {0}; // 用于记录每个位

    scanf("%d %d", &a, &n);

    // 记录低位产生的进位信息
    int carry = 0;

    // 是否产生了进位，用于在进位导致位置可能超过n时判断当前位置是否需要加一
    int hasChanged = 0;

    // 记录当前位置
    int now = 0;

    // 当前位置不一定是局限于n,当数字很大时进位可能导致位置超过n
    for (int i = 0; i <= now; i++)
    {

        // 未产生进位之前的各位之和
        int base = (n - now >= 0) ? n - now : 0;

        // 原本值加上进位
        arr[i] = a * base + carry;

        // 修改进位
        carry = (arr[i] >= 10) ? arr[i] / 10 : 0;

        // 是否产生了进位，因为需要记录上一步的进位，所以不能通过进位本身来判断
        hasChanged = (arr[i] >= 10) ? 1 : 0;

        // 产生进位之后剩下的值作为该位的值
        arr[i] = (arr[i] >= 10) ? arr[i] % 10 : arr[i];

        // 当前位置加一的条件是：在 0 - (n - 2)之间一定会加一。或者当前位置大于 n - 1(即最高位)
        // 需要借助当前位的进位，如果向前产生了进位则加一
        if (i < n - 1 || (i >= n - 1 && hasChanged == 1))
        {
            now++;
        }

        // 每次循环完毕后将值还原
        hasChanged = 0;
    }

    // 低位是从0开始的，所以反向输出
    for (int i = now; i >= 0; i--)
    {
        printf("%d", arr[i]);
    }

    printf("\n");

    return 0;
}