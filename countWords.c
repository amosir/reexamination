#include <stdio.h>
#include <string.h>
#define SIZE 20

int countWords(char str[])
{
    int count = 0;
    if (str[0] != ' ')
    {
        count = 1;
    }
    for (int i = 1; str[i] != '\0'; i++)
    {
        if (str[i] != ' ' && str[i - 1] == ' ')
        {
            count++;
        }
    }
    return count;
}
int main()
{
    char str[SIZE];
    fgets(str, SIZE, stdin);
    int len = strlen(str);
    printf("%d\n", countWords(str));
    return 0;
}