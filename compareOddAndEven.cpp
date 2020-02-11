#include <iostream>
using namespace std;
int main()
{
    int cnt;
    while (cin >> cnt && cnt != 0)
    {
        int oddCnt = 0, evenCnt = 0;
        for (int i = 0; i < cnt; i++)
        {
            int temp;
            cin >> temp;
            if ((temp & 1) == 0)
            {
                evenCnt++;
            }
            else
            {
                oddCnt++;
            }
        }
        if (evenCnt > oddCnt)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}