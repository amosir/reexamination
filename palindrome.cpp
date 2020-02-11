#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string in;
    vector<string> vec;
    while (getline(cin, in))
    {
        int len = in.length();
        for (int i = 0, j = len - 1; i < j; i++, j--)
        {
            if (in[i] != in[j])
            {
                vec.push_back("No!");
                break;
            }
            else
            {
                if (i + 1 == j)
                {
                    vec.push_back("Yes!");
                }
            }
        }
    }
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
    return 0;
}