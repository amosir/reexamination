#include <stdio.h>
#include <string.h>
#define LEN 201
int main()
{
    char str[LEN];
    while (gets(str))
    {
        if (strcmp("ENDOFINPUT", str) == 0)
        {
            return 0;
        }
        if (strcmp("START", str) == 0 || strcmp("END", str) == 0)
        {
            continue;
        }
        else
        {
            for (int i = 0; str[i] != '\0'; i++)
            {
                if (str[i] >= 'A' && str[i] <= 'Z')
                {
                    str[i] = (str[i] - 'A' + 21) % 26 + 'A';
                }
            }
            printf("%s\n", str);
        }
    }
    return 0;
}
