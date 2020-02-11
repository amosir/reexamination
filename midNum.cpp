#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int cnt;
    while (cin >> cnt && cnt != 0)
    {
        vector<int> vec(cnt);
        for (int i = 0; i < cnt; i++)
        {
            cin >> vec[i];
        }
        sort(vec.begin(), vec.end());

        if ((cnt & 1) == 1)
        {
            cout << vec[cnt / 2] << endl;
        }
        else
        {
            cout << (vec[cnt / 2] + vec[cnt / 2 - 1]) / 2 << endl;
        }
    }
    return 0;
}