#include <iostream>
#include <algorithm>
using namespace std;
// 转化为16位二进制
string decimal_to_bits(int number)
{
    string remain;
    while (number != 0)
    {
        int temp = number % 2;
        number /= 2;
        remain.push_back(temp + '0');
    }
    int align0 = 16 - remain.length();
    for (int i = 0; i < align0; i++)
    {
        remain.push_back('0');
    }
    reverse(remain.begin(), remain.end());
    return remain;
}
int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        if (a == b)
        {
            cout << "YES" << endl;
            continue;
        }
        string a_bits = decimal_to_bits(a);
        string b_bits = decimal_to_bits(b);
        int i;
        for (i = 0; i < 16; i++)
        {
            // 左移1位
            a_bits = a_bits.substr(1, 15) + a_bits[0];
            if (a_bits == b_bits)
            {
                cout << "YES" << endl;
                break;
            }
        }
        if (i == 16)
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}