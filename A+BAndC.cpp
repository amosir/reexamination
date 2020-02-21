#include <iostream>
#include <string>
using namespace std;
int main()
{
    int cnt;
    for (int i = 1; i <= cnt; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a + b > c)
        {
            cout << "Case #" + to_string(i) << ":"
                 << "true" << endl;
        }
        else
        {
            cout << "Case #" + to_string(i) << ":"
                 << "false" << endl;
        }
    }
    return 0;
}