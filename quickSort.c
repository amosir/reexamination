#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 100
int getPivot(int nums[], int left, int right)
{
    // 产生一个随机索引并与left位置交换
    srand(time(NULL));
    int index = rand() % (right - left + 1) + left;
    int temp = nums[index];
    if (index != left)
    {
        nums[index] = nums[index] ^ nums[left];
        nums[left] = nums[left] ^ nums[index];
        nums[index] = nums[index] ^ nums[left];
    }
    while (left < right)
    {
        while (left < right && nums[right] >= temp)
        {
            right--;
        }
        nums[left] = nums[right];
        while (left < right && nums[left] <= temp)
        {
            left++;
        }
        nums[right] = nums[left];
    }
    nums[left] = temp;
    return left;
}
void quickSort(int nums[], int left, int right)
{
    if (left < right)
    {
        // 获得枢纽位置
        int pivot = getPivot(nums, left, right);
        // 对枢纽位置两边的子数组递归地进行快排
        quickSort(nums, left, pivot - 1);
        quickSort(nums, pivot + 1, right);
    }
}
int main()
{
    int nums[MAX_SIZE];
    int cnt;
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++)
    {
        scanf("%d", &nums[i]);
    }
    quickSort(nums, 0, cnt - 1);
    for (int i = 0; i < cnt; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}