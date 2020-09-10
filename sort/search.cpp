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

int main(){
    
}