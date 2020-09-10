#include <iostream>
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

int main(){
    int arr[9] {1,2,6,5,4,3,8,9,7};
    cout << selectMax(arr, 9);
}