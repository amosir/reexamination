#include <iostream>
#include <string>
using namespace std;
bool symmetrySquare(int num)
{
    int _square = num * num;
    string _square_str = to_string(_square);
    for (int left = 0, right = _square_str.length() - 1; left < right; left++, right--)
    {
        if (_square_str[left] != _square_str[right])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    for (int i = 0; i <= 256; i++)
    {
        if (symmetrySquare(i))
        {
            cout << i << endl;
        }
    }
    return 0;
}