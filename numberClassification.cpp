#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main()
{
    vector<int> count(6, 0);
    vector<int> nums(6, 0);

    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        int temp;
        cin >> temp;
        // A1类
        if (temp % 5 == 0)
        {
            if (temp % 2 == 0)
            {
                count[1]++;
                nums[1] += temp;
            }
        }
        // A2类
        if (temp % 5 == 1)
        {
            if (count[2] % 2 == 0)
            {
                nums[2] += temp;
            }
            else
            {
                nums[2] -= temp;
            }
            count[2]++;
        }

        // A3类
        if (temp % 5 == 2)
        {
            count[3]++;
        }
        // A4类
        if (temp % 5 == 3)
        {
            count[4]++;
            nums[4] += temp;
        }
        // A5类
        if (temp % 5 == 4)
        {
            if (temp > nums[5])
            {
                nums[5] = temp;
            }
            count[5]++;
        }
    }
    if (count[1] == 0)
    {
        cout << "N ";
    }
    else
    {
        cout << nums[1] << " ";
    }

    if (count[2] == 0)
    {
        cout << "N ";
    }
    else
    {
        cout << nums[2] << " ";
    }

    if (count[3] == 0)
    {
        cout << "N ";
    }
    else
    {
        cout << count[3] << " ";
    }

    if (count[4] == 0)
    {
        cout << "N ";
    }
    else
    {
        cout << fixed << setprecision(1) << float(nums[4]) / count[4] << " ";
    }

    if (count[5] == 0)
    {
        cout << "N";
    }
    else
    {
        cout << nums[5] << endl;
    }
    return 0;
}