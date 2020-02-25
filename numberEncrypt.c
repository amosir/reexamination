#include <stdio.h>
#include <string.h>
void reverse(char *ch, int len)
{
    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        ch[i] = ch[i] ^ ch[j];
        ch[j] = ch[j] ^ ch[i];
        ch[i] = ch[i] ^ ch[j];
    }
}
int main()
{

    char ch[13] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'J', 'Q', 'K'};

    char A[101], B[101];
    scanf("%s %s", A, B);

    int lenA = strlen(A);
    int lenB = strlen(B);

    reverse(A, lenA);
    reverse(B, lenB);

    // 当前处理奇数位还是偶数位，等于1表示奇数位，0表示偶数位
    int oddOrEven = 1;
    int maxLen = lenA > lenB ? lenA : lenB;
    for (int i = 0; i < maxLen; i++)
    {

        int tempA = i < lenA ? A[i] - '0' : 0;
        int tempB = i < lenB ? B[i] - '0' : 0;
        if (oddOrEven == 1)
        {
            B[i] = ch[(tempA + tempB) % 13];
            oddOrEven = 0;
        }
        else
        {
            B[i] = ch[(tempB - tempA + 10) % 10];
            oddOrEven = 1;
        }
    }

    reverse(B, lenB);
    printf("%s", B);
    return 0;
}