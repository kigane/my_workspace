/*
    给定一个K个整数的序列。找该序列的连续子序列的最大和，并输出子序列的第一个和最后一个元素。
    PS：如果有多个最大和相等的子序列，则输出序号最前的那个。如果序列元素全为负，则最大和为0，输出整个序列的首尾元素。
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include "myutils.h"
using namespace std;

int main()
{
    bool flag = false;
    ifstream ifs("test_case/mss.txt");
    int n, in[100];
    ifs >> n;
    for (int i = 0; i < n; i++)
    {
        ifs >> in[i];
        if (in[i] > 0)
            flag = true;
    }

    // 处理序列元素全为负的特殊情况
    if (!flag)
    {
        cout << "子序列最大和为：" << 0 << " 首位为：" << in[0] << " 末位为：" << in[n - 1] << endl;
        return 0;
    }

    int dp[100]{}; // 以第in[i]结尾的连续子序列最大和
    int s[100]{};  // 以第in[i]结尾的最大连续子序列的开始位置

    dp[0] = in[0];

    for (int i = 1; i < n; i++)
    {
        if (dp[i - 1] + in[i] > in[i])
        {
            s[i] = s[i - 1];
            dp[i] = dp[i - 1] + in[i];
        }
        else
        {
            dp[i] = in[i];
            s[i] = i;
        }
    }

    // 找出最大子序列
    int k = 0;
    for (int i = 0; i < n; i++)
        if (dp[i] > dp[k])
            k = i;

    cout << "子序列最大和为：" << dp[k] << " 首位为：" << in[s[k]] << " 末位为：" << in[k] << endl;
}