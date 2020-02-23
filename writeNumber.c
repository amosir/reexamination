#include <stdio.h>
#include <string.h>
static char readAs[10][5] = {"ling",
                             "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
int main()
{
    char nums[101];
    int sum = 0;
    scanf("%s", nums);
    for (int i = strlen(nums) - 1; i >= 0; i--)
    {
        sum += (nums[i] - '0');
    }
    int pos = 0;
    int ans[10];
    while (sum != 0)
    {
        ans[pos++] = sum % 10;
        sum /= 10;
    }

    for (int i = pos - 1; i >= 0; i--)
    {
        printf("%s", readAs[ans[i]]);
        if (i != 0)
        {
            printf(" ");
        }
        else
        {
            printf("\n");
        }
    }
    return 0;
}