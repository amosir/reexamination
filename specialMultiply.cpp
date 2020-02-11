#include <iostream>
#include <string>
using namespace std;
int main()
{
    int a, b;

    while (cin >> a >> b)
    {
        int sum = 0;
        string str_a = to_string(a);
        string str_b = to_string(b);
        for (int i = 0; i < str_a.length(); i++)
        {
            for (int j = 0; j < str_b.length(); j++)
            {
                sum += (str_a[i] - '0') * (str_b[j] - '0');
            }
        }
        cout << sum << endl;
    }
}