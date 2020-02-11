#include<iostream>
#include<vector>
#include<string>
#include<ctype.h>
using namespace std;
// 用符号栈顶的符号对数字栈顶部的两个数进行运算
void simpleCalculate(vector<double> &num_vec,vector<char> &operator_vec){
    // 运算符栈顶部的运算符
    char operator_top = operator_vec.back();

    double num2 = num_vec.back();
    num_vec.pop_back();
    double num1 = num_vec.back();
    num_vec.pop_back();

    double temp;
    switch(operator_top){
        case '+': temp = num1 + num2;break;
        case '-': temp = num1 - num2;break;
        case '*': temp = num1 * num2;break;
        case '/': temp = num1 / num2;break;
    }
    num_vec.push_back(temp);
    operator_vec.pop_back();
}
int main(){
    // 数字栈
    vector<double> num_vec;
    // 运算符栈
    vector<char> operator_vec;

    string expression;
    cin >> expression;
    for(int i = 0;i < expression.length();i++){

        // 数字
        if(isdigit(expression[i])){
            int temp = expression[i] - '0';
            int j;
            for(j = i+1;j < expression.length() && isdigit(expression[j]);j++){
                temp = temp * 10 + (expression[j] - '0');
            }
            num_vec.push_back(temp);
            i = j - 1;
        }
        // +,- 符号
        else if(expression[i] == '+' || expression[i] == '-'){
            if(operator_vec.empty()){
                operator_vec.push_back(expression[i]);
            }else{
                simpleCalculate(num_vec,operator_vec);
                i--;
            }
        }
        // *,/ 符号
        else if(expression[i] == '*' || expression[i] == '/'){
            if(operator_vec.empty() || operator_vec.back() == '+' || operator_vec.back() == '-'){
                operator_vec.push_back(expression[i]);
            }else{
                simpleCalculate(num_vec,operator_vec);
                i--;
            }
        }
    }

    // 对符号栈剩下的符号运算
    while(num_vec.size()!=1){
        simpleCalculate(num_vec,operator_vec);
    }

    cout << num_vec.back() << endl;
    return 0;
}