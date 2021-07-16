/*
    最大连续子序列和
    给定一个数字序列，求使相邻的任意个数的子序列的和最大的子序列的和。
*/

#include <iostream>
#include "myutils.h"
using namespace std;

// 非dp解法 O(n)
void mcs(int nums[])
{
    int max = 0, i = 0, amax = 0, sub_start, start, end;
    while (i < 6)
    {
        if (nums[i] > 0 && max <= 0) // 最大子串必从正数开始累积
        {
            max = nums[i];
            sub_start = i; // 记录子串起点
        }
        else // 累积
            max = max + nums[i];

        // 记录全局最大值
        if (max > amax)
        {
            amax = max;
            start = sub_start; // 记录起点
            end = i; // 记录终点
        }
        i++;
    }

    cout << "最大子串和为：" << amax << endl;
    for (int i = start; i <= end; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main()
{
    int nums[6] {-2, 11, -14, 13, 5, -2};
    mcs(nums);
    int dp[6] {0};

    // 边界
    dp[0] = nums[0];
    // 自底向上
    for (int i = 1; i < 6; i++)
        // 状态转移方程
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
    
    // 找最大值
    int m = 0;
    for (int i = 0; i < 6; i++)
    {
        if (dp[i] > dp[m])
            m = i;
    }
    // printArr(dp, 6);
    cout << "最大子串和为：" << dp[m] << endl;
}