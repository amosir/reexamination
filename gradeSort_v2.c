#include <stdio.h>
#define MAX_CNT 100
typedef struct student
{
    int number;
    int grade;
} student;

int comp(student stu1, student stu2)
{
    return (stu1.grade == stu2.grade) ? stu1.number < stu2.number : stu1.grade < stu2.grade;
}
void sort(student stus[], int size, int (*comp)(student a, student b))
{
    for (int i = 1; i < size; i++)
    {
        student temp = stus[i];
        int j;
        for (j = i - 1; j >= 0 && !comp(stus[j], temp); j--)
        {
            stus[j + 1] = stus[j];
        }
        stus[j + 1] = temp;
    }
}
int main()
{
    int cnt;
    student stus[MAX_CNT];
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++)
    {
        scanf("%d %d", &stus[i].number, &stus[i].grade);
    }
    sort(stus, cnt, comp);

    for (int i = 0; i < cnt; i++)
    {
        printf("%d %d\n", stus[i].number, stus[i].grade);
    }
    return 0;
}