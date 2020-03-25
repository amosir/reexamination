#include <stdio.h>
int main()
{
    int cnt, sum = 0;
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++)
    {
        int age;
        scanf("%d", &age);
        sum += age;
    }
    printf("%.2f\n", 1.0 * sum / cnt);
    return 0;
}