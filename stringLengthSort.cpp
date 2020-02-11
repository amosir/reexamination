#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compareLength(string str1, string str2)
{
    return str1.length() < str2.length();
}
int main()
{
    int cnt;
    vector<string> strs;
    while (cin >> cnt)
    {
        for (int i = 0; i < cnt; i++)
        {
            string temp;
            getline(cin, temp);
            if (temp == "stop")
            {
                sort(strs.begin(), strs.end(), compareLength);
                for (int i = 0; i < strs.size(); i++)
                {
                    cout << strs[i] << endl;
                }
                strs.clear();
                return 0;
            }
            else
            {
                strs.push_back(temp);
            }
        }
        sort(strs.begin(), strs.end(), compareLength);
        for (int i = 0; i < strs.size(); i++)
        {
            cout << strs[i] << endl;
        }
        strs.clear();
    }
    return 0;
}
