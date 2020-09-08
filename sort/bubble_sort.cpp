#include <iostream>
#include <algorithm>
#include "myutils.h"
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] < arr[j])
                swap(arr[i], arr[j]);
        }        
    }    
}

int main(){
    int arr[9] {3,2,1,4,5,6,8,7,9};
    bubbleSort(arr, 9);
    printArr(arr, 9);
}