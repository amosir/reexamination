#include <iostream>
#include <vector>
using namespace std;
// 移动一个元素到to
void move(vector<int> &from, vector<int> &to)
{
    to.push_back(from.back());
    from.pop_back();
}
// 将盘子从A移动到C
void hanoi(vector<int> &A, vector<int> &B, vector<int> &C, int n)
{
    // 只有一个盘子直接移动到C
    if (n == 1)
    {
        move(A, C);
    }
    // 不止一个时先将n-1个盘子从A移动到B
    // 在将最后一个盘子移动到C,最后将n-1个盘子从
    // B移动到C
    else
    {
        hanoi(A, C, B, n - 1);
        move(A, C);
        hanoi(B, A, C, n - 1);
    }
}
int main()
{
    int plates;
    cin >> plates;
    vector<int> A(plates);
    vector<int> B;
    vector<int> C;

    // A处有三个盘子
    for (int i = 0; i < plates; i++)
    {
        A[i] = plates - i;
    }

    hanoi(A, B, C, plates);

    // 从下到上打印第三个支架上的盘子
    for (int i = 0; i < plates; i++)
    {
        cout << C[i] << " ";
    }
    return 0;
}