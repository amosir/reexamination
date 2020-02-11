#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(pair<int, int> s1, pair<int, int> s2)
{
    return s1.second == s2.second ? s1.first < s2.first :
        s1.second < s2.second;
}
int main()
{
    int cnt = 0;
    cin >> cnt;
    vector<pair<int, int> > vec;
    for (int i = 0; i < cnt; i++)
    {
        int number, grade;
        cin >> number >> grade;
        vec.push_back(pair<int, int>(number, grade));
    }
    stable_sort(vec.begin(), vec.end(), comp);
    for (int i = 0; i < cnt; i++)
    {
        cout << vec[i].first << " " << vec[i].second << endl;
    }
    return 0;
}