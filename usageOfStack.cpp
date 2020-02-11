#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int cnt;
    while (cin >> cnt && cnt != 0)
    {
        vector<int> vec;

        for (int i = 0; i < cnt; i++)
        {
            char ch;
            cin >> ch;
            switch (ch)
            {
            case 'P':
            {
                int num;
                cin >> num;
                vec.push_back(num);
            }
            break;

            case 'O':
            {
                if (vec.size() > 0)
                {
                    vec.pop_back();
                }
            }
            break;
            case 'A':
            {
                if (vec.size() > 0)
                {
                    cout << vec.back() << endl;
                }
                else
                {
                    cout << (char)'E' << endl;
                }
            }
            break;
            }
        }
        cout << endl;
    }
    return 0;
}
