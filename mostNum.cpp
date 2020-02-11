#include <iostream>
using namespace std;
int main()
{
    int number[21];
    for (int i = 0; i <= 20; i++)
    {
        number[i] = 0;
    }
    for (int i = 0; i < 20; i++)
    {
        int temp;
        cin >> temp;
        number[temp]++;
    }
    int max = 0;
    for (int i = 1; i < 20; i++)
    {
        if (number[i] > number[max])
        {
            max = i;
        }
    }
    cout << max << endl;
    return 0;
}