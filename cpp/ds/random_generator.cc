#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    int i, n = 0, N = 5000;
    double x, y, pi;
    srand((int)time(0));
    for (i = 0; i < N; i++)
    {
        x = (double)(rand() % 1000) / 1000;
        y = (double)(rand() % 1000) / 1000;
        if (x*x + y*y < 1.0)
            n++;
    }
    pi = (4 * (double)n) / (double)N;
    cout << n << endl;
    cout << pi << endl;
    
    return 0;
}