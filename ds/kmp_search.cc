#include <iostream>
#include <cstring>

using namespace std;

int prefix[20] = {};

void get_prefix(string pat)
{
    int len = pat.length();
    prefix[0] = -1;
    int i = 0, j = -1;
    while (i < len)
    {
        // 如果只有一个字符
        // 如果下一个字符和next[i]+1位置的匹配，则next[i+1]=next[i]+1
        // 否则,拉动 pattern 串
        if (j == -1 || pat[i] == pat[j])
        {
            i++;j++;prefix[i]=j; 
        }
        else
        {
            j = prefix[j];
        }
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
    string text = "abaaabaabac";
    string pattern = "abaabac";
    int res = kmp_search(text, pattern, 0);
    cout << res;
    for (int i = 0; i < pattern.length(); i++)
    {
        cout << prefix[i] << ",";
    }
    
    return 0;
}
