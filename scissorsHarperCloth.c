#include <stdio.h>
static char int2char[3] = {'B', 'C', 'J'};
int map2int(char ch)
{
    // 布
    if (ch == 'B')
        return 0;
    // 石头
    if (ch == 'C')
        return 1;
    // 剪刀
    if (ch == 'J')
        return 2;
    return -1;
};

int main()
{
    // 甲乙胜平负的场数
    int times_a[3] = {0};
    int times_b[3] = {0};
    // 甲乙三种手势出现的次数
    int gesture_a[3] = {0};
    int gesture_b[3] = {0};

    // 甲乙出的手势
    char g_a, g_b;
    // 甲乙手势对应的数字
    int i_a, i_b;
    int total;
    scanf("%d", &total);
    for (int i = 0; i < total; i++)
    {
        getchar();
        scanf("%c %c", &g_a, &g_b);
        i_a = map2int(g_a);
        i_b = map2int(g_b);

        // 平局
        if (i_a == i_b)
        {
            times_a[1]++;
            times_b[1]++;
        }
        // 甲胜
        if ((i_a + 1) % 3 == i_b)
        {
            times_a[0]++;
            times_b[2]++;
            gesture_a[i_a]++;
        }

        // 乙胜
        if ((i_b + 1) % 3 == i_a)
        {
            times_a[2]++;
            times_b[0]++;
            gesture_b[i_b]++;
        }
    }

    printf("%d %d %d\n", times_a[0], times_a[1], times_a[2]);
    printf("%d %d %d\n", times_b[0], times_b[1], times_b[2]);

    int maxA = 0, maxB = 0;
    for (int i = 1; i < 3; i++)
    {
        if (gesture_a[i] > gesture_a[maxA])
        {
            maxA = i;
        }
        if (gesture_b[i] > gesture_b[maxB])
        {
            maxB = i;
        }
    }
    printf("%c %c\n", int2char[maxA], int2char[maxB]);
    return 0;
}