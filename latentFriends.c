#include <stdio.h>
#define MAX_CNT 200
int main()
{
    // commonBooks[i]表示i号书有多少人喜欢
    int commonBooks[MAX_CNT];
    // readerLike[i]表示读者i喜欢的书编号
    int readerLike[MAX_CNT];

    int readerCnt, bookCnt;
    scanf("%d %d", &readerCnt, &bookCnt);

    for (int i = 0; i < MAX_CNT; i++)
    {
        commonBooks[i] = 0;
        readerLike[i] = 0;
    }

    for (int j = 0; j < readerCnt; j++)
    {
        int book;
        scanf("%d", &book);
        readerLike[j] = book;
        commonBooks[book]++;
    }

    for (int k = 0; k < readerCnt; k++)
    {
        if (commonBooks[readerLike[k]] > 1)
        {
            printf("%d\n", commonBooks[readerLike[k]] - 1);
        }
        else
        {
            printf("BeiJu\n");
        }
    }
    return 0;
}
