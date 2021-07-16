#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int icp(char ch)
{
    switch (ch)
    {
    case '#':
        return 0;
    case '(':
        return 6;
    case '*': case '/': case '%':
        return 4;
    case '+': case '-':
        return 2;
    case ')':
        return 1;
    default:
        return -1;
    }
}

int isp(char ch)
{
    switch (ch)
    {
    case '#':
        return 0;
    case '(':
        return 1;
    case '*': case '/': case '%':
        return 5;
    case '+': case '-':
        return 3;
    case ')':
        return 6;
    default:
        return -1;
    }
}
/*
    基本逻辑：栈顶元素和栈外元素比，若栈外元素优先级高，则入栈，若栈外元素优先级低，出栈，输出。相等，则为 ) 或结束标记。
    括号最优先的实现：进栈前优先级最高，进栈后最低，左右括号进栈前后优先级相反
    相同优先级的从左到右计算：进栈后优先级+1，则栈顶和栈外是同一优先级的元素时，会输出栈顶元素。即先进栈的先输出，先左后右。
*/
int main(){
    stack<char> s;
    char ch = '#', top, op;
    s.push(ch);
    // 手动输入一个中缀表达式
    cin >> ch;
    while (!s.empty())
    {
        if (isdigit(ch))
        {
            cout << ch;
            cin >> ch;
        }
        else
        {
            top = s.top();
            if (isp(top) < icp(ch)) //* 遇到高优先级符号，+-遇*/，*/遇括号
            {
                s.push(ch);
                cin >> ch;
            }
            else if (isp(top) > icp(ch)) //* 遇到同优先级或低优先级符号
            {
                cout << top;
                s.pop();
            }
            else
            {
                s.pop(); // '(' 不输出
                if (top == '(') // 如果没结束，继续输入
                    cin >> ch;
                else
                    break;
            }
        }
        
    }
    
}