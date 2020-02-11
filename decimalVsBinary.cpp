#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// 十进制转二进制
string decimalToBinary(string number)
{

    // 只有一个0
    if (number.length() == 1 && number[0] == '0')
    {
        return "0";
    }
    else
    {
        vector<char> vec;
        while (!number.empty())
        {
            int temp = 0;
            int len = number.length();
            for (int i = 0; i < len; i++)
            {
                // 每一位的商
                char ch = (temp * 10 + (number[i] - '0')) / 2 + '0';
                // 每一位的余数
                temp = (temp * 10 + (number[i] - '0')) % 2;
                number[i] = ch;
            }

            // 最后一位的余数
            vec.push_back(temp + '0');
            // 删除开头的0对整体的商继续进行求余数
            int j = 0;
            while (j < number.length() && number[j] == '0')
            {
                number.erase(number.begin());
            }
        }
        string str(vec.begin(), vec.end());
        return str;
    }
}

string binaryToDecimal(string binaryString)
{
    vector<char> vec;
    while (!binaryString.empty())
    {
        int temp = 0;
        int len = binaryString.length();
        for (int i = 0; i < len; i++)
        {
            char ch = (temp * 2 + (binaryString[i] - '0')) / 10 + '0';
            temp = (temp * 2 + (binaryString[i] - '0')) % 10;
            binaryString[i] = ch;
        }
        vec.push_back(temp + '0');

        int j = 0;
        while (j < binaryString.length() && binaryString[j] == '0')
        {
            binaryString.erase(binaryString.begin());
        }
    }
    string str(vec.begin(), vec.end());
    reverse(str.begin(), str.end());
    return str;
}
int main()
{
    string number;
    cin >> number;
    string binaryReversed = decimalToBinary(number);
    cout << binaryToDecimal(binaryReversed) << endl;
    return 0;
}