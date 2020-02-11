#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// 结果数组
static vector<string> vec;
// 标记数组
static bool flag[26];

// 三个参数是原字符串、当前位置、临时字符串
void permutation(string originalString, int pos, string sequence)
{
    int len = originalString.length();
    // 一次排列完毕
    if (pos == len)
    {
        vec.push_back(sequence);
        return;
    }
    else
    {
        for (int i = 0; i < len; i++)
        {
            // 没有访问过
            if (flag[originalString[i]] == false)
            {
                // 设置访问标志
                flag[originalString[i]] = true;
                sequence.push_back(originalString[i]);
                // 排列下一个位置
                permutation(originalString, pos + 1, sequence);
                // 还原
                sequence.pop_back();
                flag[originalString[i]] = false;
            }
        }
    }
}
int main()
{
    string str;
    cin >> str;
    sort(str.begin(), str.end());
    int len = str.length();
    for (int i = 0; i < 26; i++)
    {
        flag[i] = false;
    }

    // 从第一个位置开始
    permutation(str, 0, "");
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
    cout << endl;
    return 0;
}