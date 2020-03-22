#include <stdio.h>
#include <string.h>
#define SIZE 100
typedef struct
{
    char name[15];
    int grade;
} student;

// 降序
int desc(int a, int b)
{
    return a < b ? 1 : 0;
}

// 升序
int asc(int a, int b)
{
    return a > b ? 1 : 0;
}

// 插入排序
void sort(student stu[], int size, int (*comp)(int a, int b))
{
    for (int i = 1; i < size; i++)
    {
        student temp = stu[i];
        int j;
        for (j = i - 1; j >= 0 && comp(stu[j].grade, temp.grade); j--)
        {
            stu[j + 1] = stu[j];
        }
        stu[j + 1] = temp;
    }
}
int main()
{
    student stu[SIZE];

    // 总数和排序方式
    int total = 0, sortType = 0;
    scanf("%d %d", &total, &sortType);
    for (int i = 0; i < total; i++)
    {
        scanf("%s %d", stu[i].name, &(stu[i].grade));
    }

    // 降序
    if (sortType == 0)
    {
        sort(stu, total, desc);
    }

    // 升序
    else if (sortType == 1)
    {
        sort(stu, total, asc);
    }

    for (int i = 0; i < total; i++)
    {
        printf("%s %d\n", stu[i].name, stu[i].grade);
    }
    return 0;
}