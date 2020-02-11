#include <iostream>
using namespace std;
int main()
{
    int cnt;
    cin >> cnt;

    int *arr = new int[1001];
    for (int i = 0; i < 1001; i++)
    {
        arr[i] = 0;
    }
    for (int i = 0; i < cnt; i++)
    {
        int temp;
        cin >> temp;
        arr[temp]++;
    }

    int k;
    cin >> k;

    int order = 1;

    for (int j = 1; j < 1001; j++)
    {
        if (arr[j] != 0)
        {
            if (order == k)
            {
                cout << j;
                return 0;
            }
            else
            {
                order++;
                continue;
            }
        }
    }
    return 0;
}