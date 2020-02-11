#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string num;
    int temp[30];
    vector<int> vec;
    while (cin >> num)
    {
        bool flag = false;
        for (int k = 2; k <= 9; k++)
        {
            int x = 0;
            for (int i = 0; i < num.size(); i++)
            {
                x = (x * 10 + (num[i] - '0')) % k;
            }
            if (x == 0)
            {
                vec.push_back(k);
                flag = true;
            }
        }
        if (flag == false)
        {
            cout << "none" << endl;
        }
        else
        {
            for (int j = 0; j < vec.size(); j++)
            {
                if (j == vec.size() - 1)
                {
                    cout << vec[j] << endl;
                }
                else
                {
                    cout << vec[j] << " ";
                }
            }
            vec.clear();
        }
    }
    return 0;
}