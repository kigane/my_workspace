#include <iostream>
#include <algorithm>
#include "myutils.h"
using namespace std;

const int MIN = 0x80000000;

int partition(int[], int, int);
int partition2(int[], int, int);

// 蛮力选择
// 选最大
int selectMax(int arr[], int n)
{
    int max = MIN, index = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            index = i;
        }
    }
    return index;
}

// 线性时间选择rank k元素
int selectK(int arr[], int l, int r, int k)
{
    if (l == r)
        return arr[l];
    int q = partition(arr, l, r);
    int x = q - l + 1; // x是q在当前数组区间的阶数
    if (x == k) // pivot正好是
        return arr[q];
    else if (k < x) // pivot的阶比k大，则在pivot左边递归找rank k的元素
        return selectK(arr, l, q - 1, k);
    else // pivot的阶比k小，则在pivot右边找，并且取到pivot及其左边所有比pivot小的元素后，找k阶元素变为找k-x阶元素
        return selectK(arr, q + 1, r, k - x);
}

int selectMedianIn5(int arr[])
{
    int a,b,c,d,e;
    a = arr[0];
    b = arr[1];
    c = arr[2];
    d = arr[3];
    e = arr[4];

    // 保证 c < d, a < b 
    if (a >= b)
        swap(a, b);
    if (c >= d)
        swap(c, d);
    
    // 保证 a < c < d , a < b 
    if (a >= c)
    {
        swap(a, c);
        swap(b, d);
    }

    if (b < e)
    {
        if (b < c)
            return c < e ? c : e;
        else
            return  b < d ? b : d;
    }
    else
    {
        if (e < c)
            return c < b ? c : b;
        else
            return e < d ? e : d;
    }
}

int main(){
    int arr[5] {2,2,5,4,4};
    cout << selectMedianIn5(arr);
}

int partition(int arr[], int l, int r)
{
    int pos = l;
    int pivot = arr[l];
    for (int i = l + 1; i <= r; i++)
    {
        if (arr[i] < pivot)
        {
            pos++;
            swap(arr[i], arr[pos]);
        }
    }
    swap(arr[l], arr[pos]);
    return pos;
}

int partition2(int arr[], int l, int r)
{
    int pivot = arr[l];
    while (l < r)
    {
        while (l < r && arr[r] > pivot)
            r--;
        while (l < r && arr[l] < pivot)
            l++;
        swap(arr[l], arr[r]);
    }
    arr[l] = pivot;
    return l;
}