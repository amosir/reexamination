#include <stdio.h>
#define SIZE 200
int main()
{
    int nums[SIZE];
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    scanf("%d", &x);

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == x)
        {
            printf("%d\n", i);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}
