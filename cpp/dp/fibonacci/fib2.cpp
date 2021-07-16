#include <iostream>
using namespace std;

// 动态规划自底向上法(不保存用不到的子问题)
int fib(int n)
{
    int a = 0, b = 1; // fib(0), fib(1)
    if (n < 0) 
        return -1;
    if (n == 0)
        return a;
    while (0 < n--)
    {
        b = a + b;
        a = b - a;
    }
    return b;
}

// 自顶向下法，记忆化搜索
int dp[100] {0};
int fib_dp(int n)
{
    if(n <= 1)
        return n;
    if (!dp[n])
        dp[n]  = fib_dp(n - 1) + fib_dp(n - 2);
    return dp[n];
}

int main()
{
    cout << fib(44) << endl;
    cout << fib_dp(45) << endl;
}
