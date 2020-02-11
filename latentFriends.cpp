#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    // 每个人喜欢的书
    vector<int> books(N);
    // 每本书喜欢的人数
    vector<int> commonLikes(M, 0);
    for (int i = 0; i < N; i++)
    {
        int book;
        cin >> book;
        books[i] = book;
        commonLikes[book]++;
    }
    for (int i = 0; i < N; i++)
    {
        if (commonLikes[books[i]] > 1)
        {
            cout << commonLikes[books[i]] - 1 << endl;
        }
        else
        {
            cout << "BeiJu" << endl;
        }
    }
    return 0;
}