#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ret = 0;
    for (int i = 1; i <= n; i++)
    {
        // false表示与7无关
        bool flag = false;
        if (i % 7 == 0)
        {
            flag = true;
        }
        string temp = to_string(i);
        for (int j = temp.length(); j >= 0; j--)
        {
            if (temp[j] == '7')
            {
                flag = true;
            }
        }

        if (!flag)
        {
            ret += i * i;
        }
    }
    cout << ret << endl;
    return 0;
}