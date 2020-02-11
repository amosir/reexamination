#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    while (getline(cin, str))
    {
        if (str.length() == 1 && str[0] == '!')
        {
            return 0;
        }
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] = 'z' - (str[i] - 'a');
            }
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] = 'Z' - (str[i] - 'A');
            }
        }
        cout << str << endl;
    }
    return 0;
}