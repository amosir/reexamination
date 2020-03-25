#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX_LEN 10
int main()
{
    char hex_str[MAX_LEN];
    while (scanf("%s", hex_str) != EOF)
    {
        int sum = 0;
        int len = strlen(hex_str);
        for (int i = len - 1; i >= 2; i--)
        {
            if (hex_str[i] >= '0' && hex_str[i] <= '9')
            {
                sum = sum + pow(16, len - i - 1) * (hex_str[i] - '0');
            }
            else
            {
                sum = sum + pow(16, len - i - 1) * (hex_str[i] - 'A' + 10);
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}