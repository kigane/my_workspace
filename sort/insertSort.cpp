#include <iostream>
#include "myutils.h"
using namespace std;

void insertSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i], j;
        for (j = i; temp < arr[j-1]; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
    }
}

int main(){
    int arr[9]{3, 2, 1, 4, 5, 6, 8, 7, 9};
    insertSort(arr, 9);
    printArr(arr, 9);
}