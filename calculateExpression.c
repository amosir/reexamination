#include <stdio.h>
#include <ctype.h>
#define MAX_LEN 50
// 用操作符栈顶部运算符对数字栈顶部两个元素进行运算
void calculate(char operators[], int *top1, double numbers[], int *top2)
{
    // 栈顶操作符
    char top_operator = operators[(*top1)--];

    // 两个操作数
    double num2 = numbers[(*top2)--];
    double num1 = numbers[(*top2)--];

    double temp = 0;
    switch (top_operator)
    {
    case '+':
        temp = num1 + num2;
        break;
    case '-':
        temp = num1 - num2;
        break;
    case '*':
        temp = num1 * num2;
        break;
    case '/':
        temp = num1 / num2;
        break;
    }
    // 计算结果入栈
    numbers[++(*top2)] = temp;
}
int main()
{
    // 保存输入的字符串
    char expression[MAX_LEN];
    scanf("%s", expression);

    // 操作符栈和数字栈及其栈顶指针
    char operators[MAX_LEN];
    double numbers[MAX_LEN];
    int top_ope_index = -1, top_num_index = -1;

    for (int i = 0; i < MAX_LEN && expression[i] != '\0'; i++)
    {
        // 分离表达式中的数字
        if (isdigit(expression[i]))
        {
            int temp = expression[i] - '0';
            int j = i + 1;
            while (j < MAX_LEN && expression[j] != '\0' && isdigit(expression[j]))
            {
                temp = temp * 10 + (expression[j++] - '0');
            }
            numbers[++top_num_index] = temp;
            // 将i指到最近的一个数字字符，这样i++才会指到下一个未分析的字符
            i = j - 1;
        }
        // +-运算符
        else if (expression[i] == '+' || expression[i] == '-')
        {
            //操作符栈为空则入栈
            if (top_ope_index == -1)
            {
                operators[++top_ope_index] = expression[i];
            }
            // 操作符栈不空则从操作符栈顶取出操作符,从数字栈顶取出两个数字进行运算
            else
            {
                calculate(operators, &top_ope_index, numbers, &top_num_index);
                // 计算之后栈内可能还需要消解,所以当前运算符需要再次处理
                i--;
            }
        }
        else if (expression[i] == '*' || expression[i] == '/')
        {
            // 栈空或栈顶部运算符优先级低于当前运算符
            if (top_ope_index == -1 || operators[top_ope_index] == '+' || operators[top_ope_index] == '-')
            {
                operators[++top_ope_index] = expression[i];
            }
            else
            {
                calculate(operators, &top_ope_index, numbers, &top_num_index);
                i--;
            }
        }
    }
    // 此时运算符栈有一个运算符,数字栈有两个操作数
    while (top_num_index > 0)
    {
        calculate(operators, &top_ope_index, numbers, &top_num_index);
    }
    printf("%d\n", (int)numbers[top_num_index]);
    return 0;
}