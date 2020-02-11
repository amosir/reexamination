#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 分割日志
vector<string> split_log_str(string str)
{
    int len = str.length();
    vector<string> vec;
    string temp = "";
    for (int i = 0; i < len; i++)
    {
        if (str[i] != ' ')
        {
            temp += str[i];
        }
        else
        {
            if (temp != "")
            {
                vec.push_back(temp);
                temp = "";
            }
        }
    }
    if (temp != "")
    {
        vec.push_back(temp);
    }
    return vec;
}
bool compare_log(string a, string b)
{
    vector<string> part_a = split_log_str(a);
    vector<string> part_b = split_log_str(b);
    if (part_a[3].length() < part_b[3].length())
    {
        return true;
    }
    else if (part_a[3].length() > part_b[3].length())
    {
        return false;
    }
    else
    {
        if (part_a[3] == part_b[3])
        {
            return part_a[1] + part_a[2] < part_b[1] + part_b[2];
        }
        else
        {
            return part_a[3] < part_b[3];
        }
    }
}
int main()
{
    string str;
    vector<string> vec;
    while (getline(cin, str) && str.length() != 0)
    {
        vec.push_back(str);
    }

    sort(vec.begin(), vec.end(), compare_log);
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
    return 0;
}