#include <iostream>
#include <algorithm>
using namespace std;

int G[8];
int sum_of_solutions = 0;

void Queen(int G[], int i)
{
    int j, k;
    bool conflict;

    if (i == 8) // 结束条件
    {
        for (int m = 0; m < 8; m++)
        {
            for (int n = 0; n < 8; n++)
            {
                if (n == G[m])
                    cout << "1 ";
                else
                    cout << "0 ";
            }
            cout << endl;            
        }
        cout << "=======" << ++sum_of_solutions << "=======" << endl;
        return;
    }

    for (j = 0; j < 8; j++) // 八个选择--方向
    {
        conflict = false;
        for (k = 0; k < i; k++) // 遍历已经摆好的皇后
        {
            if (j == G[k] || i - k == j - G[k] || i - k == G[k] - j) // 列不同，斜线不同
                conflict = true;
        }
        if (!conflict)
        {
            G[i] = j;
            Queen(G, i + 1);
        }
    }
}

int main(){
    fill(G, G+8, 0);
    Queen(G, 0);    
}