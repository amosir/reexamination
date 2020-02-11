#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(string str1, string str2)
{
    int len1 = str1.length();
    int len2 = str2.length();
    for (int i = 0; i <)
}
int main()
{
    vector<string> vec;
    string str;
    while (getline(cin, str))
    {
        vec.push_back(str);
    }
    stable_sort(vec.begin(), vec.end(), comp);
}