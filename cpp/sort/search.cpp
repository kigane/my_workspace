#include <iostream>
using namespace std;

// 蛮力查找 -- 键值没有任何特殊组织
bool searchKey(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return true;
    }
    return false;
}

// 二分查找 -- 键值有序
int binary_search(int arr[], int n, int key)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main(){
    int arr[9] {1,2,3,4,5,6,7,8,9};
    for (int i = 0; i < 9; i++)
    {
        cout << binary_search(arr, 9, i) << endl;
    }   
    
}