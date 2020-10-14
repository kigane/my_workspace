#include <iostream>
#include <cstring>

using namespace std;

int prefix[20] = {};
int nextval[20] = {};

void get_prefix(string pat)
{
    int len = pat.length();
    prefix[0] = -1;
    int i = 0, j = -1;
    while (i < len)
    {
        // next[0]=-1,next[1]=0
        // j始终在i前面，j相当于最大前缀后一位，i相当于最大后缀后一位。
        // 如果下一个字符(i++)和next[i]+1(j=prefix[j],j++)位置的匹配，则next[i+1]=next[i]+1
        // 否则,拉动 pattern 串
        if (j == -1 || pat[i] == pat[j])
        {
            i++;j++;prefix[i]=j;
        }
        else // i,j 失配，相当于子串0..j和模式串失配，用kmp方法找最大相等前后缀。
            j = prefix[j];
    }
}

void get_nextval(string pat)
{
    int len = pat.length();
    nextval[0] = -1;
    int i = 0, j = -1, k;
    while (i < len)
    {
        if (j == -1 || pat[i] == pat[j])
        {
            i++;j++;nextval[i]=j;
            k = j;
            while (pat[i] == pat[k]) // 如果pat[i] 和 pat[next[i]] 相等，则原来不匹配，转到next还是不可能匹配，继续找next的next
            {
                nextval[i] = nextval[k];
                k = nextval[k];
            }
        }
        else
            j = nextval[j];
    }
}

int kmp_search(string text, string pat, int pos)
{
    get_prefix(pat);
    int i = pos, j = 0;
    while (i < text.length() && j < pat.length())
    {
        if (j == -1 || text[i] == pat[j])
        {
            i++;j++;
        }
        else
            j = prefix[j];
    }
    if (j < pat.length())
        return -1;
    else
        return i - pat.length();
}

int main(int argc, char const *argv[])
{
    // string text = "abaaabacabaaadabaabac";
    string pattern = "abcaabbcabcaabdab";
    // int res = kmp_search(text, pattern, 0);
    // cout << res  << endl;
    get_nextval(pattern);
    for (int i = 0; i < pattern.length(); i++)
    {
        cout << nextval[i]+1 << ",";
    }
    
    return 0;
}
