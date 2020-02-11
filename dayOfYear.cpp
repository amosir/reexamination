#include <iostream>
using namespace std;
int main()
{
    int dayOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year, month, day;
    while (cin >> year >> month >> day)
    {
        int days = 0;
        if (1 <= year && year <= 3000 && month >= 1 && month <= 12 && day >= 1 && day <= 31)
        {
            if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
            {
                dayOfMonth[2] = 29;
            }
            for (int i = 1; i < month; i++)
            {
                days += dayOfMonth[i];
            }
            days += day;
            cout << days << endl;
            dayOfMonth[2] = 28;
        }
    }
}