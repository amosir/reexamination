#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vec;
    int n, temp, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        vec.push_back(temp);
    }

    cin >> x;

    for (int i = 0; i < n; i++)
    {
        if (vec[i] == x)
        {
            cout << i;
            return 0;
        }
    }

    cout << -1;
    return 0;
}
