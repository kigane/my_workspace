#include <iostream>
using namespace std;

bool knapsack(int s, int n, int weight[])
{
    if (s == 0)
        return true;
    if (s < 0 || (s > 0 && n < 1))
        return false;
    if (knapsack(s - weight[n - 1], n - 1, weight)) // 选择了某件物品
    {
        cout << "result n=" << n << "w[" << n - 1 << "]=" << weight[n - 1];
        return true;
    }
    else // 没选某件物品
        return knapsack(s, n - 1, weight);
}

int main(){
    int w[8] {11, 3, 5, 7, 4, 9, 2, 6};
    if (knapsack(46, 8, w))
        cout << "有解" << endl;
    else
        cout << "无解" << endl;
}