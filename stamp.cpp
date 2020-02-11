#include <iostream>
#include <set>
using namespace std;
int main()
{
    set<int> stampSet;
    // 8角的5张
    for (int i = 0; i <= 5; i++)
    {
        // 一元的4张
        for (int j = 0; j <= 4; j++)
        {
            // 一元八角的6张
            for (int k = 0; k <= 6; k++)
            {
                int total = 8 * i + 10 * j + 18 * k;
                if (stampSet.find(total) == stampSet.end())
                {
                    stampSet.insert(total);
                }
            }
        }
    }
    cout << stampSet.size() - 1 << endl;
    return 0;
}