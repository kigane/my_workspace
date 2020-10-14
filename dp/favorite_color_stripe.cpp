/*
    Eva想要制定她自己的色带。在给定的色彩序列中，以她喜欢的次序保留她最喜欢的颜色。
    输入  第一行：N总的颜色数
         第二行：第一个数字是Eva喜欢的色彩的数量 后面是具体的色彩
         第三行：第一个数字是给定色带的数量 后面是具体的颜色
    示例：
        给定色带{2 2 4 1 5 6 3 1 1 5 6}
        Eva 喜好{2 3 1 5 6}
        输出结果：7 
        对应的结果：{2 2 1 1 1 5 6} {2 2 1 5 5 5 6} {2 2 1 5 5 6 6} 或 {2 2 3 1 1 5 6}
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include "myutils.h"
using namespace std;

int main()
{
    int N, M, L, hashtable[200], A[200], x;
    fill(hashtable, hashtable + 100, -1);
    ifstream ifs("test_case/fcs.txt");
    ifs >> N;
    ifs >> M;
    /* LIS法
    for (int i = 0; i < M; i++) // 建立将颜色映射为序的映射关系
    {
        ifs >> x;
        hashtable[x] = i;
    }
    ifs >> L;
    int num = 0;
    for (int i = 0; i < L; i++)
    {
        ifs >> x;
        if (hashtable[x] >= 0) // 剔除不再列表中的元素
            A[num++] = hashtable[x]; // 将颜色映射成序
    }

    int dp[200] {}; // 以第i个元素结尾的最长非降子序列的长度
    int ans = -1;
    for (int i = 0; i < num; i++) // 遍历终点
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++) // 遍历子问题
            if(A[j] <= A[i] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] +1;
        ans = max(ans, dp[i]);
    }
    */
    for (int i = 1; i <= M; i++)
        ifs >> hashtable[i];
    ifs >> L;
    for (int i = 1; i <= L; i++)
        ifs >> A[i];

    int dp[200][200];
    // 边界条件
    for (int i = 0; i <= M; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= L; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= L; j++)
        {
            int MAX = max(dp[i - 1][j], dp[i][j - 1]);
            if (A[j] == hashtable[i])
                dp[i][j] = MAX + 1;
            else
                dp[i][j] = MAX;
        }
    }

    cout << dp[M][L] << endl;
}