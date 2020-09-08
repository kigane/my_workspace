#include <iostream>
#include <stack>
using namespace std;

int baseTrans(int N, int B)
{
    int i, result = 0;
    stack<int> s;
    while (N != 0)
    {
        i = N % B;
        N = N / B;
        s.push(i);
    }
    while (!s.empty())
    {
        i = s.top();
        s.pop();
        result = 10 * result + i;
    }
    
    return result;
}

int main(){
    cout << baseTrans(32, 16) << endl;
}