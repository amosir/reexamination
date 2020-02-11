#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main()
{
    int cnt;
    while (cin >> cnt)
    {
        for (int i = 0; i < cnt; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            if (a == 0)
            {
                cout << "Not quadratic equation" << endl;
                continue;
            }
            else
            {

                int delta = b * b - 4 * a * c;
                if (delta == 0)
                {
                    cout << setiosflags(ios::fixed) << setprecision(2) << "x=" << endl;
                    cout.unsetf(ios::fixed);
                }
                else if (delta > 0)
                {
                    cout << setiosflags(ios::fixed) << setprecision(2) << "x1=" << (-b - sqrt(delta)) / (2 * a) << ","
                         << "x2=" << (-b + sqrt(delta)) / (2 * a) << endl;
                    cout.unsetf(ios::fixed);
                }
                else
                {
                    cout << -1 << endl;
                }
            }
        }
    }
    return 0;
}