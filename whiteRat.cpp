#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compDesc(pair<int, string> r1, pair<int, string> r2)
{
    return r1.first > r2.first;
}
int main()
{
    int ratCnt;
    cin >> ratCnt;
    vector<pair<int, string> > rats;
    for (int i = 0; i < ratCnt; i++)
    {
        int weigh;
        string color;
        cin >> weigh >> color;
        rats.push_back(pair<int, string>(weigh, color));
    }
    sort(rats.begin(), rats.end(), compDesc);
    for (int j = 0; j < rats.size(); j++)
    {
        cout << rats[j].second << endl;
    }
    return 0;
}