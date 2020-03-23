#include <stdio.h>
#include <string.h>
typedef struct Stu
{
    char number[5];
    char name[10];
    char sex[5];
    int age;
} Stu;
int main()
{
    Stu stus[1000];
    // 学生数和查找数
    int stuCnt, findCnt;
    scanf("%d", &stuCnt);
    for (int i = 0; i < stuCnt; i++)
    {
        scanf("%s %s %s %d", stus[i].number, stus[i].name, stus[i].sex, &stus[i].age);
    }
    scanf("%d", &findCnt);
    // 吸收回车符
    getchar();
    for (int i = 0; i < findCnt; i++)
    {
        char temp[5];
        scanf("%s", temp);
        // 吸收回车符
        getchar();
        int flag = 0;
        // 查找
        for (int j = 0; j < stuCnt; j++)
        {
            if (strcmp(stus[j].number, temp) == 0)
            {
                printf("%s %s %s %d\n", stus[j].number, stus[j].name, stus[j].sex, stus[j].age);
                flag = 1;
                break;
            }
        }
        // 没找到
        if (flag == 0)
        {
            printf("No Answer!\n");
        }
    }
    return 0;
}