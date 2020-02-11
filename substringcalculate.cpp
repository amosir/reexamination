#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    string str;
    while (cin >> str && str != " ")
    {
        map<string, int> substring_map;
        for (int i = 1; i <= str.length(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                substring_map[str.substr(j, i - j)]++;
            }
        }

        for (map<string, int>::iterator it = substring_map.begin(); it != substring_map.end(); it++)
        {
            if (it->second > 1)
            {
                cout << it->first << " " << it->second << endl;
            }
        }
    }
    return 0;
}