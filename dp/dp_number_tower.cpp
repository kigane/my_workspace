/*
    数塔问题
    将一些数字排列成塔的形状，第n层有n个数字
    每次只能走向下一层邻接的两个数字之一
    问：将路径上所有数字相加后得到的和最大是多少？
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "myutils.h"
using namespace std;

const int maxn = 100;

int f[maxn][maxn] {};
int dp[maxn][maxn] {};

int ntdp(int n, int m)
{
    // 边界
    if (n == 4)
        return f[n][m];
    // 自顶向下，递归，memo机制
    if (!dp[n][m])
        dp[n][m] = max(ntdp(n+1, m), ntdp(n+1, m+1)) + f[n][m];
    return dp[n][m];
}

int main()
{
    string loc = "number_tower.txt";
    ifstream file(loc);

    // 数塔输入
    int n = 5;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            file >> f[i][j];

    // 边界
    for (int j = 0; j < n; j++)
        dp[n-1][j] = f[n-1][j];
    
    // 计算dp，自底向上
    for (int i = n - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            dp[i][j] = max(dp[i+1][j], dp[i+1][j+1])+f[i][j];
    
    // 计算，自顶向下
    // int ans = ntdp(0, 0);

    cout << "最大和为：" << dp[0][0] << endl;
}