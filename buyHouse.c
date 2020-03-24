#include <stdio.h>
int main()
{
    int salary, rate, price = 200;
    while (scanf("%d %d", &salary, &rate) != EOF)
    {
        int total = salary;
        int flag = 0;
        for (int i = 0; i < 20; i++)
        {
            total += salary;
            price = ((rate + 100) / 100.0) * price;
            if (price <= total)
            {
                flag = 1;
                printf("%d\n", i + 2);
                break;
            }
        }
        if (flag == 0)
        {
            printf("Impossible\n");
        }
    }
    return 0;
}