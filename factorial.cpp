#include <iostream>
#define LEN 1000
using namespace std;
int main()
{
    int factorial[LEN];

    for (int i = 0; i < LEN; i++)
    {
        factorial[i] = 0;
    }

    factorial[0] = 1;

    int num;

    while (cin >> num)
    {
        for (int i = 2; i <= num; i++)
        {
            int carry = 0;
            for (int j = 0; j < LEN; j++)
            {
                int temp = factorial[j] * i + carry;
                factorial[j] = temp % 10;
                carry = temp / 10;
            }
        }

        for (int k = LEN - 1; k >= 0; k--)
        {
            if (factorial[k] != 0)
            {
                while (k >= 0)
                {
                    cout << factorial[k];
                    k--;
                }
            }
        }
        cout << endl;
    }
    return 0;
}