#include <stdio.h>
#define LEN 10
int main()
{
    char num1[LEN], num2[LEN];
    scanf("%s %s", num1, num2);
    int sum = 0;
    for (int i = 0; num1[i] != '\0'; i++)
    {
        for (int j = 0; num2[j] != '\0'; j++)
        {
            sum += (num1[i] - '0') * (num2[j] - '0');
        }
    }
    printf("%d\n", sum);
    return 0;
}