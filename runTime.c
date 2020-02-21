#include <stdio.h>
int main()
{
    int c1, c2;
    scanf("%d %d", &c1, &c2);
    // 时钟打点数差
    int dis = c2 - c1;

    // dis % 100表示不足一秒的部分，
    // 求四舍五入之后的秒数
    if (dis % 100 >= 50)
    {
        dis = dis / 100 + 1;
    }
    else
    {
        dis = dis / 100;
    }

    // %02d表示2位宽度，不足补0
    printf("%02d:%02d:%02d\n", dis / 3600, dis % 3600 / 60, dis % 60);
}