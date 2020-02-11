#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main()
{
    vector<int> nums(10);
    int oddPos = 0, evenPos = 9;
    for (int i = 0; i < 10; i++)
    {
        int temp;
        cin >> temp;
        if ((temp & 1) == 1)
        {
            nums[oddPos++] = temp;
        }
        else
        {
            nums[evenPos--] = temp;
        }
    }
    sort(nums.begin(), nums.begin() + oddPos, greater<int>());
    sort(nums.begin() + oddPos, nums.end(), less<int>());
    for (int i = 0; i < 10; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}