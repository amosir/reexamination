#include <iostream>
#include <vector>
#include<math.h>
using namespace std;
int main()
{
    int cnt;
    cin >> cnt;
    // 指数、系数
    vector<pair<int, int> > vec;
    for (int i = 0; i < cnt; i++)
    {
        int highest;
        cin >> highest;
        for (int j = 0; j <= highest; j++)
        {
            int coef;
            cin >> coef;
            vec.push_back(pair<int, int>(j, coef));
        }
        int x;
        cin >> x;
        int result = 0;
        for (int i = 0; i <= highest; i++)
        {
            result += pow(x,vec[i].first) * vec[i].second;
        }
        cout << result << endl;
    }
    return 0;
}