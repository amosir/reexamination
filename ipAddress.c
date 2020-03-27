#include <stdio.h>
#define MAX_LEN 20
int isValid(int num)
{
    if (num < 0 || num > 255)
    {
        return 0;
    }
    return 1;
}
int main()
{
    int a, b, c, d;
    while (scanf("%d.%d.%d.%d", &a, &b, &c, &d) != EOF)
    {
        if (isValid(a) && isValid(b) && isValid(c) && isValid(d))
        {
            printf("Yes!\n");
        }
        else
        {
            printf("No!\n");
        }
    }
    return 0;
}