#include <iostream>
#include "myutils.h"
using namespace std;

int b[2][2] {{1, 1}, {1, 0}};

// 2*2 矩阵相乘
void matrix_multiply(int a[2][2], int b[2][2])
{
    int x, y, z, w;
    x = a[0][0]*b[0][0] + a[0][1]*b[1][0];
    y = a[0][0]*b[0][1] + a[0][1]*b[1][1];
    z = a[1][0]*b[0][0] + a[1][1]*b[1][0];
    w = a[1][0]*b[0][1] + a[1][1]*b[1][1];
    a[0][0] = x;
    a[0][1] = y;
    a[1][0] = z;
    a[1][1] = w;
}

// 快速幂
void rapid_pow(int a[2][2], int n)
{
    if (n <= 1)
        return;
    
    rapid_pow(a, n / 2);
    matrix_multiply(a, a);
    
    if (n % 2 == 1)
        matrix_multiply(a, b);
}

// 通过矩阵快速幂求fibonacci数
int fibonacci_matrix(int n)
{
    if (n <= 1) // f(0) = 0, f(1) =1
        return n;
    int a[2][2] {{1, 1}, {1, 0}};
    rapid_pow(a, n - 1);
    return a[0][0];
}

int main()
{
    cout << fibonacci_matrix(55) << endl;
}