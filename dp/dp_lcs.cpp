/*
    最长公共子序列(Longest Common Subsequence)
    给定两个字符串A,B，求一个字符串的长度。这个字符串是AB的最长公共部分(子序列可以不连续)
    例：sadstory 和 adminsorry 的LCS为 adsory 长度为6
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include "myutils.h"
using namespace std;

int dp[100][100];

int main()
{
    string A = "sadstory";
    string B = "adminsorry";
    // 边界条件
    for (int i = 0; i <= A.length(); i++)
        dp[0][i] = 0;

    for (int i = 0; i <= B.length(); i++)
        dp[i][0] = 0;

    // 自底向上
    for (int i = 1; i <= A.length(); i++)
    {
        for (int j = 1; j <= B.length(); j++)
        {
            if (A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << "最长公共子序列长度为：" << dp[A.length()][B.length()] << endl;
}