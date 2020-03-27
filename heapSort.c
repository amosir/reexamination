#include <stdio.h>
#define MAX_SIZE 1000
void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
void adjustDown(int nums[], int pos, int len)
{
    // 待调整位置的元素
    int temp = nums[pos];
    // 从该节点左孩子开始,将以该节点为根节点的子树的最大值交换到该位置
    for (int i = 2 * pos + 1; i < len; i = i * 2 + 1)
    {
        // 右孩子存在且比左孩子大
        if (i + 1 < len && nums[i] < nums[i + 1])
        {
            i++;
        }
        // 交换
        if (nums[i] > temp)
        {
            swap(&nums[i], &nums[pos]);
            pos = i;
        }
    }
    nums[pos] = temp;
}
// 大根堆
void heapSort(int nums[], int len)
{
    for (int i = len / 2 - 1; i >= 0; i--)
    {
        adjustDown(nums, i, len);
    }

    // 将堆顶元素与数组尾部进行交换，然后调整剩下的元素
    for (int i = len - 1; i > 0; i--)
    {
        swap(&nums[0], &nums[i]);
        adjustDown(nums, 0, i);
    }
}
int main()
{
    int cnt;
    scanf("%d", &cnt);

    int nums[MAX_SIZE];
    for (int i = 0; i < cnt; i++)
    {
        scanf("%d", &nums[i]);
    }
    // 堆排序
    heapSort(nums, cnt);
    // 输出最大数
    printf("%d\n", nums[cnt - 1]);

    // 去掉最大数后没有剩余的数
    if (cnt == 1)
    {
        printf("-1\n");
        return 0;
    }
    for (int i = 0; i < cnt - 1; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}