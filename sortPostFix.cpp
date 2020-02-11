#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<string> vec;
    string str;
    cin >> str;
    for (int i = 0; i <= str.length() - 1; i++)
    {
        vec.push_back(str.substr(i, str.length() - i));
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
    return 0;
}