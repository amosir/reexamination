#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        int num;
        cin >> num;
        int temp = 0;
        int sq = sqrt(num);
        for (int j = 1; j <= sq; j++)
        {
            if (num % j == 0)
            {
                if (j * j == num)
                {
                    temp += 1;
                }
                else
                {
                    temp += 2;
                }
            }
        }
        cout << temp << endl;
    }
    return 0;
}
