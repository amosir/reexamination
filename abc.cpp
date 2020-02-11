#include <iostream>
using namespace std;
int main()
{
    for (int a = 1; a <= 5; a++)
    {
        for (int b = 1; b <= 5; b++)
        {
            for (int c = 0; c <= 9; c++)
            {
                if (a * 100 + b * 10 + c + b * 100 + c * 10 + c == 532)
                {
                    cout << a << " " << b << " " << c << endl;
                }
            }
        }
    }
    return 0;
}