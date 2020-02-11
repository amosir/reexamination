#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;

// 是否含有模式串
bool contains(string str, string pattern)
{
    if (str.find(pattern) != string::npos)
    {
        return true;
    }
    return false;
}

// 交换字符串第i个字符及其后面的字符,i不能取最后一个字符位置
string swap_i(string str, int i)
{
    string retStr = str;
    char ch = retStr[i];
    retStr[i] = retStr[i + 1];
    retStr[i + 1] = ch;
    return retStr;
}

// 深度优先搜索
int bfs(string str, string pattern)
{
    // 记录字符串交换的次数
    map<string, int> timesMap;
    // 辅助队列
    queue<string> qu;
    qu.push(str);
    timesMap.insert(pair<string, int>(str, 0));

    while (!qu.empty())
    {
        str = qu.front();
        qu.pop();
        for (int i = 0; i < str.length() - 1; i++)
        {
            string tempStr = swap_i(str, i);
            if (timesMap.find(tempStr) != timesMap.end())
            {
                continue;
            }
            else
            {
                timesMap[tempStr] = timesMap[str] + 1;
                if (contains(tempStr, pattern))
                {
                    return timesMap[tempStr];
                }
                qu.push(tempStr);
            }
        }
    }

    return -1;
}
int main()
{
    string pattern = "2012";
    int len;
    while (cin >> len)
    {
        string str;
        cin >> str;
        if (contains(str, pattern))
        {
            cout << 0 << endl;
        }
        else
        {
            cout << bfs(str, pattern);
        }
    }
    return 0;
}