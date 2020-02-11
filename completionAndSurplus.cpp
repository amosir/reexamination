#include <iostream>
#include <vector>
using namespace std;
int judge(int num)
{
    int sum = 1;
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }
    if (sum == num)
    {
        return 0;
    }
    if (sum > num)
    {
        return 1;
    }
    return -1;
}
int main()
{
    vector<int> completion;
    vector<int> surplus;
    for (int i = 2; i <= 60; i++)
    {
        int type = judge(i);
        if (type == 0)
        {
            completion.push_back(i);
        }
        if (type == 1)
        {
            surplus.push_back(i);
        }
    }
    cout << "E: ";
    for (int j = 0; j < completion.size(); j++)
    {
        if (j < completion.size() - 1)
        {
            cout << completion[j] << " ";
        }
        else
        {
            cout << completion[j];
        }
    }
    cout << endl;
    cout << "G: ";
    for (int j = 0; j < surplus.size(); j++)
    {
        if (j < surplus.size() - 1)
        {
            cout << surplus[j] << " ";
        }
        else
        {
            cout << surplus[j];
        }
    }
    cout << endl;
}