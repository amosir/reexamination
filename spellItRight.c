#include <stdio.h>
static char numChar[10][6] = {"zero", "one", "two", "three", "four",
                              "five", "six", "seven", "eight",
                              "nine"};
void printBits(int num)
{
    if (num < 10)
    {
        printf("%s", numChar[num]);
        return;
    }
    printBits(num / 10);
    printf(" %s", numChar[num % 10]);
}
int main()
{
    char num[102];
    int sum = 0;
    scanf("%s", num);

    // 各位之和
    for (int i = 0; num[i] != '\0'; i++)
    {
        sum += (num[i] - '0');
    }

    printBits(sum);

    return 0;
}