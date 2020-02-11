#include <iostream>
#include <vector>
using namespace std;
int gcd(int x, int y)
{
    while (y != 0)
    {

        int temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}
int main()
{
    int cnt;
    while (cin >> cnt)
    {

        int total = 0;
        int num[cnt];
        for (int i = 0; i < cnt; i++)
        {
            int temp;
            cin >> temp;
            num[i] = temp;
        }
        for (int i = 0; i < cnt; i++)
        {
            for (int j = 0; j < cnt; j++)
            {
                if (num[i] == num[j])
                {
                    continue;
                }
                if (num[i] > num[j] && gcd(num[i], num[j]) == 1)
                {
                    total++;
                }
            }
        }
        cout << total << endl;
    }
    return 0;
}