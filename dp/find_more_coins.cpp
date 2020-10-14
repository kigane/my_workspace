/*
    有N枚硬币，给出每枚硬币面值，现要用这些硬币去支付价值为M的物品。
    问：有没有选出一些硬币恰好凑够价值M。如果没有，输出No Solution，如果有，输出字典序最小的那个。
    相当于重量和价值相等的01背包问题
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include "myutils.h"
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int N, M, val[100];
    ifstream ifs("test_case/coin.txt");
    ifs >> N;
    ifs >> M;
    for (int i = 1; i <= N; i++)
        ifs >> val[i]; // 记录每个硬币的面值
    
    int dp[200] {}; // 前i个硬币的最大价值
    bool choice[200][200]; // 第i个硬币在总价值为j时有没有被选中
    bool flag[200]; // 第i个硬币有没有被选中
    
    sort(val+1, val+N, cmp); // 从大到小排序，从小到大选硬币
    
    for (int i = 1; i <= N; i++) // 遍历可选硬币
    {
        for (int v = M; v >= val[i]; v--) // 滚动数组法，从右往左计算，用前i枚硬币可组成的最大价值
        {
            if (dp[v] <= dp[v - val[i]] + val[i]) // 选了第i枚硬币
            {
                dp[v] = dp[v - val[i]] + val[i];
                choice[i][v] = 1;
            }
            else // 没选第i枚硬币
                choice[i][v] = 0;
        }        
    }

    if (dp[M] != M)
        cout << "No Solution" << endl;
    else
    {
        // 记录最优路径
        int k = N, num = 0, v = M;
        while (k >= 0)
        {
            if (choice[k][v] == 1)
            {
                flag[k] = true;
                v -= val[k];
                num++;
            }
            else 
                flag[k] = false;
            k--;
        }

        // 输出方案
        for (int i = N; i >= 1; i--)
        {
            if (flag[i])
            {
                cout << val[i];
                num--;
                if (num > 0)
                    cout << " ";
            }
        }
    }
}