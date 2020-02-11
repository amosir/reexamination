#include <iostream>
using namespace std;
int main()
{
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int n;
    cin >> n;
    int *out = new int[n];
    for (int i = 0; i < n; i++)
    {
        int year, month, day, temp = 0;
        cin >> year >> month >> day;

        // 闰年2月天数
        if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
        {
            days[2] += 1;
        }

        for (int j = 1; j < month; j++)
        {
            temp += days[j];
        }

        out[i] = temp += day;

        // 还原
        days[2] = 28;
    }

    for (int i = 0; i < n; i++)
    {
        cout << out[i] << endl;
    }

    return 0;
}