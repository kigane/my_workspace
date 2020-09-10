#include <iostream>
#include <algorithm>
#include "myutils.h"
using namespace std;

int partition(int arr[], int low, int high)
{
    // 把首位当做pivot，且值取出来，low位置相当与vacancy(空位)，pivot右边元素的进来，进来以后肯定比pivot小，vacancy向后移动。
    int pivot = arr [low]; 
    while (low < high)
    {
        while (low < high && arr[high] > pivot) // 从大的开始比较
            high--;
        while (low < high && arr[low] < pivot) // vacancy右移
            low++;
        swap(arr[low], arr[high]); // 右边比pivot小的元素放入空位
    }
    arr[low] = pivot; // 最后把pivot填入空位 
    return low;
}

int partition2(int arr[], int low, int high)
{
    // vacancy, 初始是pivot，不断填入比pivot小的元素，右移。循环结束的时候存的是比pivot小的元素，和pivot交换回来，即完成。
    int pivot_pos = low, pivot = arr[low];
    for (int i = low + 1; i <= high; i++) // 遍历找比pivot小的元素
    {
        if (arr[i] < pivot)
        {
            pivot_pos++; // vacancy右移
            // if (i != pivot_pos) // 特殊情况，第一个就只pivot小，此时不用移动。移动也行，就是自己和自己换一次，不影响。
            swap(arr[i], arr[pivot_pos]); // 比pivot小的元素进来
        }
    }
    swap(arr[low], arr[pivot_pos]);  // pivot归位
    return pivot_pos;
}

void qsort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition2(arr, low, high);
        qsort(arr, low, pivot - 1);
        qsort(arr,pivot + 1, high);
    }
}

void quickSort(int arr[], int n)
{
    qsort(arr, 0, n - 1);
}

// 合并
void qSort(int arr[], int low, int high)
{
    if (low >= high)
        return;
    int pos = low, pivot = arr[low];
    for (int i = low + 1; i <= high; i++)
    {
        if (arr[i] < pivot)
        {
            pos++;
            swap(arr[pos], arr[i]);
        }
    }
    swap(arr[low], arr[pos]);
    qSort(arr, low, pos -1);
    qSort(arr, pos + 1, high);
}

int main(){
    int arr[9]{9, 8, 7, 6, 5, 4, 3, 2, 1};
    qSort(arr, 0, 8);
    printArr(arr, 9);
}