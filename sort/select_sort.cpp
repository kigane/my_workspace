#include <iostream>
#include <algorithm>
#include "myutils.h"
using namespace std;

const int MIN = 0x80000000;

// 蛮力选择
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

// 选择排序
void selectSort(int arr[], int n)
{
    int m;
    for (int i = n - 1; i > 0; i--)
    {
        m = selectMax(arr, i + 1);
        swap(arr[m], arr[i]);
    }    
}

int main()
{
    int arr[9]{3, 2, 1, 4, 5, 6, 8, 7, 9};
    selectSort(arr, 9);
    printArr(arr, 9);
}