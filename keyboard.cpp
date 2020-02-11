#include <iostream>
using namespace std;
int main()
{
    // 记录每个字符需要按得次数
    int keys[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
    string str;
    cin >> str;
    // 总时间
    int total_time = 0;
    int len = str.length();
    if (len == 0)
    {
        return 0;
    }
    else
    {
        // 第一个字符需要按得次数
        total_time = keys[str[0] - 'a'];
    }
    for (int i = 1; i < len; i++)
    {
        // 按键时间
        total_time += keys[str[i] - 'a'];
        // 等待时间
        if (str[i] - str[i - 1] == keys[str[i] - 'a'] - keys[str[i - 1] - 'a'])
        {
            total_time += 2;
        }
    }
    cout << total_time << endl;
    return 0;
}
