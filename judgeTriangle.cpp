// 根据边长判断 三角形类型
#include <stdio.h>

int main()
{

    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    int flag;

    if (a <= c && b <= c)
    {
        flag = a * a + b * b - c * c;
    }

    if (a <= b && c <= b)
    {
        flag = a * a + c * c - b * b;
    }

    if (b <= a && c <= a)
    {

        flag = b * b + c * c - a * a;
    }

    if (flag == 0)
        printf("直角三角形\n");
    if (flag > 0)
        printf("锐角三角形\n");
    else if (flag < 0)
        printf("钝角三角形\n");

    return 0;
}