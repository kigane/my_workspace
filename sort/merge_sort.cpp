#include <iostream>
#include "myutils.h"
using namespace std;

const int ASIZE = 9;
int tarr[ASIZE] {}; // 辅助数组

void merge(int arr[], int low, int mid, int high)
{
    for (int i = low; i <= high; i++) // 拷贝数据到辅助数组
        tarr[i] = arr[i];

    int i =low,  k = low, j = mid + 1;
    while (i <= mid && j <= high) // 终止条件是左右某一部分结束
    {
        if (tarr[i] <= tarr[j])
            arr[k++] = tarr[i++];
        else if ( tarr[i] > tarr[j])
            arr[k++] = tarr[j++];
    }

    // 剩下的直接添加到尾部
    while (i <= mid)
        arr[k++] = tarr[i++];
    while (j <= high)
        arr[k++] = tarr[j++];
        
}

void mergeSort(int arr[], int low, int high)
{
    if (low == high) // 递归结束条件
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main(){
    int arr[9]{9, 8, 7, 6, 5, 4, 3, 2, 1};
    mergeSort(arr, 0, 8);
    printArr(arr, 9);
}