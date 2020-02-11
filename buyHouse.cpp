#include <iostream>
using namespace std;
#include <math.h>
int main()
{
    int salary, rate, price = 200;
    while (cin >> salary >> rate)
    {
        int total = salary;
        for (int i = 0; i <= 20; i++)
        {
            total += salary;
            price = ((rate + 100) / 100.0) * price;
            if (price <= total)
            {
                cout << i + 2 << endl;
                return 0;
            }
        }
        cout << "Impossible" << endl;
    }
}