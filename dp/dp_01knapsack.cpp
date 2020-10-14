/*
    01背包问题
    有n件物品，每件物品重量为w[i]，价值为c[i]。现有一个容量为V的背包。
    问如何选取物品放入背包，使得背包内物品的总价值最大。其中每种物品都只有一件。
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
#include "myutils.h"
using namespace std;

int main()
{
    int n, V;
    ifstream ifs("knapsack.txt");
    ifs >> n >> V;
    int *w = new int(n);
    int *c = new int(n);
    for (int i = 0; i < n; i++)
        ifs >> w[i];
    for (int i = 0; i < n; i++)
        ifs >> c[i];

    /* 二维dp
    int dp[100][100] {0}; // 前i件物品恰好装入容量为V的背包中能获得的最大价值
    // 边界
    for (int i = 0; i <= V; i++)
    {
        dp[0][i] = 0;
    }
    // 每次考虑前i件物品，从第一件开始考虑，要还是不要第i件。故直接从第i件的重量开始计算dp。(小于i重量的相当于不要i，即上一行dp值)
    for (int i = 1; i <= n; i++)
    {
        for (int v = w[i-1]; v <= V; v++)
        {
            dp[i][v] = max(dp[i-1][v], dp[i-1][v-w[i-1]] + c[i-1]);
        }
    }
    */

    // 优化到一维 滚动数组法 注意到二维dp计算第n行，只需要n-1行正上方和左上方的数据
    // 因为需要左边(即上一行的数据)，因此必须从右往左遍历
    int dp[100] {}; // 初始化为 0
    for (int i = 1; i <= n; i++)
    {
        for (int v = V; v >= w[i-1]; v--)
        {
            dp[v] = max(dp[v], dp[v-w[i-1]] + c[i-1]);
        }
    }
    
    printArr(dp, V+1);
}