#include <iostream>
#include <algorithm>
#include "myutils.h"
using namespace std;

void getPermutation(int nums[], int i, int n)
{
    if (i == 0) //* 递归边界，只有一个数字需要排列
    {
        printArr(nums, 4);
    }
    else
    {
        for (int j = 0; j <= i; j++) //* 决定最后一个位置(参数i)放什么
        {
            swap(nums[i], nums[j]); //* 包含i的i个元素都放一遍 
            getPermutation(nums, i - 1, n); //* 放好最后一个元素后问题规模减一
            swap(nums[i], nums[j]); //* 位置换回来(下层递归换过去的都会换回来，在某次for循环内，调用递归前后nums数组元素位置不变)
        }
    }
}

int main()
{
    int target[3], nums[]{1, 2, 3, 4};
    getPermutation(nums, 3, 4);
}