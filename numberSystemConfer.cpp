#include <iostream>
#include <vector>
using namespace std;
// 求余数
vector<int> getRemainer(string &str)
{
    vector<int> ret;
    // 0的情况
    if (str.length() == 1 && str[0] == 0)
    {
        ret.push_back(0);
        return ret;
    }

    // 非0的情况
    else
    {
        while (!str.empty())
        {
            int temp = 0;
            int len = str.length();
            for (int i = 0; i < len; i++)
            {
                // 商
                char ch = (temp * 10 + (str[i] - '0')) / 2 + '0';
                // 余数
                temp = (temp * 10 + (str[i] - '0')) % 2;

                str[i] = ch;
            }

            // 最后一位的余数就是最终的余数
            ret.push_back(temp);
            // 删掉前面的0
            int j = 0;
            while (j < str.length() && str[j] == '0')
            {
                str.erase(str.begin());
            }
        }
    }

    return ret;
}
int main()
{
    string number;
    while (cin >> number)
    {
        // 逆序输出
        vector<int> binary = getRemainer(number);
        for (int i = binary.size() - 1; i >= 0; i--)
        {
            cout << binary[i];
        }
        cout << endl;
    }
    return 0;
}