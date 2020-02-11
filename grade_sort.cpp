#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define DESC 0
#define ASC 1
using namespace std;
bool comp_desc(pair<string, int> stu1, pair<string, int> stu2)
{
    return stu1.second > stu2.second;
}

bool comp_asc(pair<string, int> stu1, pair<string, int> stu2)
{
    return stu1.second < stu2.second;
}
int main()
{
    vector<pair<string, int> > stu_gra;
    int cnt;
    // 排序方式
    int type;
    cin >> cnt;
    cin >> type;
    for (int i = 0; i < cnt; i++)
    {
        string name;
        int grade;
        cin >> name >> grade;
        stu_gra.push_back(pair<string, int>(name, grade));
    }

    if (type == DESC)
    {
        stable_sort(stu_gra.begin(), stu_gra.end(), comp_desc);
    }
    else
    {
        stable_sort(stu_gra.begin(), stu_gra.end(), comp_asc);
    }
    for (int i = 0; i < cnt; i++)
    {
        cout << stu_gra[i].first << " " << stu_gra[i].second << endl;
    }
    return 0;
}