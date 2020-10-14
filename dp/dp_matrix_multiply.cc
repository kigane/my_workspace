#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 0x7fffffff;
int cost[10][10]{0};
int last[10][10]{0};
queue<int> Q;

void extract_order(int low, int high)
{
    int k;
    if (high - low > 1)
    {
        k = last[low][high];    // 整个问题的最好划分位置
        extract_order(low, k);  // 左子问题的最好划分位置
        extract_order(k, high); // 右子问题的最好划分位置
        Q.push(k); // 递归本身就是个栈，所以这里用队列
    }
}

int matrix_mutiply(int D[], int n)
{
    int low, high, k, cost1, cost2, cost3, best_cost, best_last;
    for (low = n - 1; low >= 0; low--) // 从下向上算
    {
        for (high = low + 1; high < n; high++) // 从左到右算
        {
            if (high - low == 1) // 单个矩阵
            {
                best_cost = 0;
                best_last = -1;
            }
            else
            {
                best_cost = INF; // 初始化最小代价
            }

            for (k = low + 1; k < high; k++) // 遍历所有可能的划分位置
            {
                cost1 = cost[low][k]; // 左子问题代价，通过调度，在之前的循环中必定已经算好了
                cost2 = cost[k][high]; // 右子问题代价，同上
                cost3 = D[low] * D[k] * D[high]; // 以 k 处为最后一次相乘位置的最后一次相乘的代价
                if (cost1 + cost2 + cost3 < best_cost) // 选出最小的 k
                {
                    best_cost = cost1 + cost2 + cost3; // 记录当前最小代价
                    best_last = k; // 记录最小代价是在哪个位置相乘的
                }
            }

            cost[low][high] = best_cost;
            last[low][high] = best_last;
        }
    }
    extract_order(0, n-1);
    return cost[0][n-1];
}

int nums[10][10];
int dp[10][10];

int main()
{
    // int D[5]{30, 1, 40, 10, 25};
    // int min_cost = matrix_mutiply(D, 5);
    // cout << min_cost << endl;
    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < 5; j++)
    //     {
    //         cout << cost[i][j] << ",";
    //     }
    //     cout << endl;
    // }
    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < 5; j++)
    //     {
    //         cout << last[i][j] << ",";
    //     }
    //     cout << endl;
    // }
    // while (!Q.empty())
    // {
    //     cout << Q.front() << endl;
    //     Q.pop();
    // }
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            scanf("%d", &nums[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        dp[n][i] = nums[n][i];
    }
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + nums[i][j];
        }
    }
    cout << dp[1][1] << endl;

    return 0;
}