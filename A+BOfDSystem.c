#include <stdio.h>
int main()
{
    int num1, num2;
    int transferTo;

    scanf("%d %d %d", &num1, &num2, &transferTo);

    int result = num1 + num2;

    if (result == 0 || transferTo == 10)
    {
        printf("%d", result);
    }

    int arr[31] = {0};
    int pos = 0;
    while (result != 0)
    {
        arr[pos++] = result % transferTo;
        result /= transferTo;
    }

    for (int i = pos - 1; i >= 0; i--)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
}