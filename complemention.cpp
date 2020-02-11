#include <iostream>
#include <vector>
using namespace std;
bool isWanShu(int num)
{
    int sum = 0;
    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }
    if (sum == num)
    {
        return true;
    }

    return false;
}
int main()
{
    int in;
    cin >> in;
    vector<int> temp;
    for (int i = 1; i <= in; i++)
    {
        if (isWanShu(i))
        {
            temp.push_back(i);
        }
    }
    int total = temp.size();
    for (int j = 0; j <= total - 1; j++)
    {
        if (j == total - 1)
        {
            cout << temp[j];
        }
        else
        {
            cout << temp[j] << " ";
        }
    }
}