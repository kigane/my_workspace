#include <iostream>
#include <algorithm>
#include "myutils.h"
using namespace std;

void shellSort(int arr[], int n)
{
    int gap = (n / 3) + 1; // Knuth提出的方法，比取n/2更优(奇数位置和偶数位置最后才会比较)。
    int k, d, temp;
    for (d = gap; d > 1; d = (d / 3) + 1) // gap 逐渐减小
    {
        for (int i = d; i < n; i++) // 插入排序
        {
            temp = arr[i];
            for (k = i - d; k >=0 && arr[k] > temp; k -= d)
            {
                arr[k + d] = arr[k];
            }
            arr[k + d] = temp; 
        }
    }
}

int main(){
    int arr[9]{3, 2, 1, 4, 5, 6, 8, 7, 9};
    shellSort(arr, 9);
    printArr(arr, 9);
}