#include <stdio.h>
struct Stu
{
    long long id;
    int examSeatNum;
} seats[1001];
int main()
{
    int stuCnt, trySeatNum, examSeatNum;
    long long id;
    scanf("%d", &stuCnt);
    for (int i = 0; i < stuCnt; i++)
    {
        scanf("%lld %d %d", &id, &trySeatNum, &examSeatNum);
        seats[trySeatNum].id = id;
        seats[trySeatNum].examSeatNum = examSeatNum;
    }
    int queryCnt;
    scanf("%d", &queryCnt);
    for (int i = 0; i < queryCnt; i++)
    {
        scanf("%d", &trySeatNum);
        printf("%lld %d\n", seats[trySeatNum].id, seats[trySeatNum].examSeatNum);
    }
    return 0;
}