#include <stdio.h>
int main()
{
    char str[5];
    scanf("%s", str);
    for (int i = 3; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}