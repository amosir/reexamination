#include <iostream>
using namespace std;
int main()
{
    int num1, num2;
    while (cin >> num1 >> num2)
    {
        while (num1 != num2)
        {
            if (num1 > num2)
            {
                num1 /= 2;
            }
            else
            {
                num2 /= 2;
            }
        }
        cout << num1 << endl;
    }
    return 0;
}