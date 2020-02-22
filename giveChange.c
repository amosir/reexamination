#include <stdio.h>
static const int galleonToKunt = 17 * 29;
static const int sickleToKunt = 29;

int main()
{
    int should_g, should_s, should_k;
    int real_g, real_s, real_k;
    scanf("%d.%d.%d %d.%d.%d", &should_g, &should_s, &should_k, &real_g, &real_s, &real_k);
    int price = should_g * galleonToKunt + should_s * sickleToKunt + should_k;
    int money = real_g * galleonToKunt + real_s * sickleToKunt + real_k;

    int change = money - price;

    if (change < 0)
    {
        printf("-");
        change = -change;
    }

    printf("%d.%d.%d\n", change / galleonToKunt, change % galleonToKunt / sickleToKunt, change % sickleToKunt);

    return 0;
}