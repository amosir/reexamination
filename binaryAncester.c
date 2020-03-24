#include <stdio.h>
int main()
{
    int num1, num2;
    while (scanf("%d %d", &num1, &num2) != EOF)
    {
        while (num1 != num2)
        {
            if (num1 > num2)
            {
                num1 /= 2;
            }
            else
            {
                num2 /= 2;
            }
        }
        printf("%d\n", num1);
    }
    return 0;
}