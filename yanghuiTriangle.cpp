#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> vec;
    for (int i = 1; i <= n - 1; i++)
    {
        vector<int> temp;
        for (int j = 1; j <= i + 1; j++)
        {
            // 两边
            if (j == 1 || j == i + 1)
            {
                temp.push_back(1);
            }
            // 中间的等于肩上两个元素之和
            else
            {
                temp.push_back(vec[i - 2][j - 1] + vec[i - 2][j - 2]);
            }
        }
        vec.push_back(temp);
    }

    for (int i = 0; i < n - 1; i++)
    {
        int len = vec[i].size();
        for (int j = 0; j < len; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}