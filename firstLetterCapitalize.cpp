#include <iostream>
#include <ctype.h>
using namespace std;
bool isBlankChar(char ch)
{
    if (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n')
    {
        return true;
    }
    return false;
}
int main()
{
    string str;
    while (getline(cin, str) && str != " ")
    {
        if (islower(str[0]))
        {
            str[0] = toupper(str[0]);
        }
        for (int i = 1, len = str.length(); i < len; i++)
        {
            if (isBlankChar(str[i - 1]) && islower(str[i]))
            {
                str[i] = toupper(str[i]);
            }
        }
        cout << str << endl;
    }
    return 0;
}