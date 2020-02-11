#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int L, M;
    while (cin >> L >> M)
    {
        vector<int> vec(L + 1, 1);
        int start, end, cnt = 0;
        for (int k = 0; k < M; k++)
        {
            cin >> start >> end;
            for (int i = start; i <= end; i++)
            {
                vec[i] = 0;
            }
        }
        for (int j = 0; j < L + 1; j++)
        {
            if (vec[j] == 1)
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}