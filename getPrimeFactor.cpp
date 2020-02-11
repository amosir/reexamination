#include <iostream>
#include <math.h>
using namespace std;
int getPrimeFactor(int num)
{
    int cnt = 0;
    int sq = sqrt(num);
    for (int i = 2; i <= sq; i++)
    {
        if (num % i == 0)
        {
            cnt += (1 + getPrimeFactor(num / i));
            break;
        }
    }
    if (cnt == 0)
    {
        cnt++;
    }
    return cnt;
}
int main()
{
    int num, count = 0;
    while (cin >> num)
    {
        cout << getPrimeFactor(num) << endl;
    }
    return 0;
}