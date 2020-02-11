#include <iostream>
using namespace std;
int gcd(int num1, int num2)
{
    int time = 1;
    if (num1 < num2)
    {
        num1 = num1 ^ num2;
        num2 = num2 ^ num1;
        num1 = num1 ^ num2;
    }
    while (num1 != num2)
    {
        if ((num1 & 1) == 0 && (num2 & 1) == 0)
        {
            num1 /= 2;
            num2 /= 2;
            time++;
        }
        else
        {
            int temp = num1 - num2;
            if (temp > num2)
            {
                num1 = temp;
            }
            else
            {
                num1 = num2;
                num2 = temp;
            }
        }
    }
    return time * num2;
}
int main()
{
    int num1, num2;
    cin >> num1 >> num2;
    cout << gcd(num1, num2) << endl;
    return 0;
}