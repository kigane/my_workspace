#include <iostream>
#include <algorithm>
#include "myutils.h"
using namespace std;

void getPermutation(int nums[], int n)
{
    if (n == 0)
    {
        printArr(nums, 3);
    }

    for (int i = 0; i < n; i++)
    {
        swap(nums[i], nums[n-1]);
        getPermutation(nums, n-1);
        swap(nums[i], nums[n - 1]);
    }
}

int main(){
    int target[3], nums[] {1, 2, 3, 4};
}