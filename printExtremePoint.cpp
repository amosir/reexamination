#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int k;
    while (cin >> k)
    {
        // 数
        vector<int> nums;

        // 极值点下标
        vector<int> extremePointIndex;
        for (int i = 0; i < k; i++)
        {
            int temp;
            cin >> temp;
            nums.push_back(temp);
        }
        if (k == 1)
        {
            cout << 0 << endl;
        }
        for (int i = 0; i < k; i++)
        {
            // 第一个元素
            if (i == 0)
            {
                if (nums[0] != nums[1])
                {
                    extremePointIndex.push_back(0);
                }
                continue;
            }

            // 最后一个元素
            else if (i == k - 1)
            {
                if (nums[i] != nums[i - 1])
                {
                    extremePointIndex.push_back(k - 1);
                }
                continue;
            }
            // 1 ~ k - 2之间的值
            if ((nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) ||
                (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]))
            {
                extremePointIndex.push_back(i);
            }
        }

        for (int i = 0; i < extremePointIndex.size(); i++)
        {
            if (i == extremePointIndex.size() - 1)
            {
                cout << extremePointIndex[i] << endl;
            }
            else
            {
                cout << extremePointIndex[i] << " ";
            }
        }
    }
    return 0;
}