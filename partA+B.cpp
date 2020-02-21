#include <iostream>
using namespace std;
int main()
{
    int A, B, DA, DB;
    cin >> A >> DA >> B >> DB;
    int PA = 0, PB = 0;
    while (A != 0)
    {
        if (A % 10 == DA)
        {
            PA = PA * 10 + DA;
        }
        A /= 10;
    }

    while (B != 0)
    {
        if (B % 10 == DB)
        {
            PB = PB * 10 + DB;
        }
        B /= 10;
    }
    cout << PA + PB << endl;
    return 0;
}