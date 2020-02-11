#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1, str2;
    cin >> str1;
    cin >> str2;
    int len1 = str1.length();
    int len2 = str2.length();
    int index1 = 0;
    int index2 = len2 - 1;
    string temp = "";
    while (index1 < len1 && index2 >= 0)
    {
        temp += str1[index1++];
        temp += str2[index2--];
    }
    cout << temp << endl;
    return 0;
}