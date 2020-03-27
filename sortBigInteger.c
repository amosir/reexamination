#include <stdio.h>
#include <string.h>
#define MAX_LEN 1001
#define MAX_CNT 100
// num1大于num2时返回1
int comp(char num1[], char num2[])
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    // num1长度大于num2
    if (len1 > len2)
    {
        return 1;
    }
    // num2长度大于num1
    else if (len2 > len1)
    {
        return -1;
    }
    // 长度相等时比较每一个字符
    else
    {
        for (int i = 0; i < len1; i++)
        {
            if (num1[i] > num2[i])
            {
                return 1;
            }
            else if (num1[i] < num2[i])
            {
                return -1;
            }
        }
        return 0;
    }
}
// 使用希尔排序对大整数进行排序
void sortBigInteger(char nums[][MAX_LEN], int size, int (*comp)(char str1[], char str2[]))
{
    // 选取一个间隔
    for (int gap = size / 2; gap > 0; gap--)
    {
        // 对每个间隔形成的分组进行插入排序
        for (int i = gap; i < size; i++)
        {
            char temp[MAX_LEN];
            strcpy(temp, nums[i]);
            int j;
            for (j = i - gap; j >= 0 && (comp(nums[j], temp) != -1); j -= gap)
            {
                strcpy(nums[j + gap], nums[j]);
            }
            strcpy(nums[j + gap], temp);
        }
    }
}
int main()
{
    int cnt;
    scanf("%d", &cnt);
    getchar();
    char nums[MAX_CNT][MAX_LEN];
    for (int i = 0; i < cnt; i++)
    {
        scanf("%s", nums[i]);
    }
    sortBigInteger(nums, cnt, comp);
    for (int i = 0; i < cnt; i++)
    {
        printf("%s\n", nums[i]);
    }
}