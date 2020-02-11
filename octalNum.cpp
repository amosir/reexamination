#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int num;
    cin >> num;
    vector<int> vec;
    while (num >= 8)
    {
        vec.push_back(num % 8);
        num /= 8;
    }
    vec.push_back(num);
    int len = vec.size();
    for (int i = len - 1; i >= 0; i--)
    {
        cout << vec.at(i);
    }
    cout << endl;
    return 0;
}