/*
    最长不下降子序列
    在一个数字序列中，找到一个最长的子序列(可以不连续)，使得这个子序列是不下降的。
*/
#include <iostream>
#include <fstream>
#include "myutils.h"
using namespace std;

int dp[100]; // 以第i个元素结尾的最长不降子序列的长度

int main()
{
    int n, ans = -1;
    ifstream ifs("nums.txt");
    ifs >> n;
    int *nums = new int(n);
    for (int i = 0; i < n; i++)
        ifs >> nums[i];
    
    dp[0] = 1;
    for (int i = 1; i < n; i++) // 按顺序计算dp
    {
        // 状态转移方程
        dp[i] = 1; // 边界条件，各元素自成一个序列
        for (int j = 0; j < i; j++) // 遍历更小的子问题
            if (nums[i] >= nums[j] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1; // 更新dp
        ans = max(ans, dp[i]);
    }
    cout << "最长非降子序列长度为：" << ans << endl;
}