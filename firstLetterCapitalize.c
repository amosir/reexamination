#include <stdio.h>
#include <ctype.h>
#define LEN 100
int main()
{
    char str[LEN];
    while (fgets(str, LEN, stdin))
    {
        if (islower(str[0]))
        {
            str[0] = toupper(str[0]);
        }
        int i;
        for (i = 1; str[i] != '\n' && str[i] != '\0'; i++)
        {
            if (isblank(str[i - 1]) && islower(str[i]))
            {
                str[i] = toupper(str[i]);
            }
        }
        str[i] = '\0';
        printf("%s\n", str);
    }
    return 0;
}