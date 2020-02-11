#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Y') ||
            (str[i] >= 'a' && str[i] <= 'y'))
        {
            str[i] += 1;
            continue;
        }
        if (str[i] == 'z')
        {
            str[i] = 'a';
            continue;
        }
        if (str[i] == 'Z')
        {
            str[i] = 'A';
            continue;
        }
    }
    cout << str << endl;
    return 0;
}
