/*
    最长回文子串(Longest Palindrome Subsequence)
    给定两个字符串A,B，求一个字符串的长度。这个字符串是AB的最长公共部分(子序列可以不连续)
    例：sadstory 和 adminsorry 的LCS为 adsory 长度为6
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include "myutils.h"
using namespace std;

int dp[100][100] {0}; // 从第i个字符到第j个字符组成的字符串是不是回文，是则为1，否则为0

int main()
{
    string S = "PATZJUJZTACCBCC";

    int len = S.length(), ans = 0;

    // 边界条件
    for (int i = 0; i < len; i++)
    {
        dp[i][i] = 1;
        if (S[i] == S[i+1] && i < len - 1)
        {
            dp[i][i+1] = 1;
            ans = 2;
        }
    }

    // 先按长度遍历，再遍历左端点
    for (int l = 3; l <= len; l++)
    {
        for (int j = 0; j < len - l + 1; j++)
        {
            if (S[j] == S[j+l-1] && dp[j+1][j+l-2] == 1)
            {
                dp[j][j+l-1] = 1;
                ans = l;
            }
        }
    }
    
    cout << "最长回文子串长度为：" << ans << endl;
}