#include <iostream>
#include <vector>
using namespace std;
int main()
{
    unsigned int num;
    cin >> num;
    vector<int> ret;
    while (num >= 2)
    {
        ret.push_back(num % 2);
        num /= 2;
    }
    ret.push_back(num);

    for (int i = ret.size() - 1; i >= 0; i--)
    {
        cout << ret[i];
    }
    return 0;
}