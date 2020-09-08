#include <iostream>
using namespace std;

int ackerman(int m, int n)
{
    if (m == 0)
        return n + 1;
    else if (n == 0)
        return ackerman(m - 1, 1);
    else
        return ackerman(m - 1, ackerman(m, n - 1));
}

int ackerman_nonrecursive(int m, int n)
{
    int i, j, res, Sm[25], Sn[25], top = -1;
    // 初始参数入栈
    Sm[++top] = m;
    Sn[top] = n;
    while (1)
    {
        i = Sm[top];
        j = Sn[top];
        top--; // 出栈

        if (i == 0) // m=0
        {
            res = j + 1;
            if (top != -1)
                Sn[top] = res; // 把空着的地方填上
            else
                return res;
        }
        else if (j == 0) // m!=0,n=0
        {
            Sm[++top] = i - 1;
            Sn[top] = 1;
        }
        else // m!=0,n!=0
        {
            Sm[++top] = i - 1; // 进栈，n待定
            Sm[++top] = i; // 再进栈
            Sn[top] = j - 1;
        }
    }
}

int main(){
    // 2,2 十层以内 3,2 要25层
    cout << ackerman_nonrecursive(3, 2) << endl;
    cout << ackerman(3, 2) << endl;
}