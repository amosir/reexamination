#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution{
private:
    int chessboard[8][8];
    vector<string> vec;
    // 初始化棋盘
    void initChessBoard(){
        for(int i = 0;i < 8;i++){
            for(int j = 0;j < 8;j ++){
                chessboard[i][j] = 0;
            }
        }
    }
    // 检查坐标(x,y)处能否放置皇后
    bool canLay(int x,int y){
        // 同一列
        for(int i = 0;i < x;i++){
            if(chessboard[i][y] == 1){
                return false;
            }
        }
        // 对角线
        for(int i = x - 1,j = y - 1;i >= 0 && j >= 0;i--,j--){
            if(chessboard[i][j] == 1){
                return false;
            }
        }

        // 副对角线
        for(int i = x - 1,j = y + 1;i >= 0 && j <= 7;i--,j++){
            if(chessboard[i][j] == 1){
                return false;
            }
        }

        return true;
    }
    // 获取一个排列方式
    void getLayout(){
        string temp = "";
        for(int i = 0;i < 8;i++){
            for(int j = 0;j < 8;j++){
                if(chessboard[i][j] == 1){
                    temp.push_back((j + 1) + '0');
                    break;
                }
            }
        }
        vec.push_back(temp);
    }
    // 填充棋盘
    void fill(int x){
        if(x > 7){
            getLayout();
            return;
        }
        for(int j = 0;j < 8;j++){
            if(canLay(x,j)){
                chessboard[x][j] = 1;
                fill(x + 1);
                chessboard[x][j] = 0;
            }
        }
    }
public:
    void eightQueen(){
        initChessBoard();
        fill(0);
    }
    // 获取第b个后面的排列
    string getLayoutAfterB(int b){
        sort(vec.begin(),vec.end());
        return vec[b - 1];
    }
};
int main(){
    Solution so;
    int b;
    so.eightQueen();
    while(cin >> b){
        cout << so.getLayoutAfterB(b) << endl;
    }
    return 0;

}