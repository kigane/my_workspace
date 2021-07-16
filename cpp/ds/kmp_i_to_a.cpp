#include <iostream>
#include <string>
using namespace std;

int *compute_prifix_function(string P)
{
    int *pi = new int[P.size()];
    pi[0] = 0;
    int k = 0;
    for (int q = 1; q < P.size(); q++)
    {
        while (k > 0 && P[k] != P[q]) //* 前后缀字符没匹配上，此时前k-1个字符是匹配上的
            k = pi[k - 1];
        if (P[k] == P[q]) //* 当前前后缀字符匹配上了
            k++;
        pi[q] = k;
    } 
    return pi; 
}

int kmp_search(string T, string P)
{
    int *pi = compute_prifix_function(P);
    int q = 0; //* q是已匹配字符的个数
    for (int i = 0; i < T.size(); i++)
    {
        while (q > 0 && P[q + 1] != T[i]) //* 这种写法不用将next数组整体右移一位
            q = pi[q] - 1;
        if (P[q + 1] == T[i])
            q++;
        if (q == P.size()-1)
            return i-q;
    }
    return -1; //* 匹配失败
}

int main(){
    string text = "abaaabcaabaaaaac";
    string pattern = "aaaaa";
    int *PI = compute_prifix_function(pattern);
    for (int i = 0; i < pattern.size(); i++)
    {
        cout << PI[i] << endl;
    }
    int res = kmp_search(text, pattern);
    cout << res << endl;
}
