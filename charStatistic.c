#include <stdio.h>
#define MAX_LEN 200
int main()

{
    int cnts[26];
    for (int i = 0; i < 26; i++)
    {
        cnts[i] = 0;
    }
    char str[MAX_LEN];
    fgets(str, MAX_LEN, stdin);
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            cnts[str[i] - 'A']++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        printf("%c:%d\n", 'A' + i, cnts[i]);
    }
    return 0;
}