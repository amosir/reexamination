#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()

{
    vector<int> ch(26);
    for (int i = 0; i < 26; i++)
    {
        ch[i] = 0;
    }
    string str;
    while (cin >> str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                ch[str[i] - 'A']++;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            cout << char('A' + i) << ":" << ch[i] << endl;
        }
    }

    return 0;
}