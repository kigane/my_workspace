#include <iostream>
#include <algorithm>
using namespace std;

typedef struct CNode
{
    int data;
    CNode *link;
} CNode;

void josephus_circle_list()
{
    CNode *c8 = new CNode{8, NULL};
    CNode *c7 = new CNode{7, c8};
    CNode *c6 = new CNode{6, c7};
    CNode *c5 = new CNode{5, c6};
    CNode *c4 = new CNode{4, c5};
    CNode *c3 = new CNode{3, c4};
    CNode *c2 = new CNode{2, c3};
    CNode *c1 = new CNode{1, c2};
    c8->link = c1;

    CNode *p = c1, *pre = NULL;
    int i = 0, j;
    while (i < 7)
    {
        j = 1;
        while (j < 3)
        {
            pre = p;
            p = p->link;
            j++;
        }
        cout << "出列的人是:" << p->data << endl;
        pre->link = p->link;
        delete p;
        p = pre->link;
        i++;
    }
    cout << p->data << endl;
}

void josephus(int n, int s, int m)
{
    if (!m)
    {
        cout << "m = 0 是无效参数" << endl;
        return;
    }
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    
    int len = n;
    s--;
    for (int i = 0; i < n - 1; i++)
    {
        s = (s + m - 1) % len--;
        cout << "出列的人是：" << arr[s] << endl;
        for (int j = s; j < len; j++)
        {
            swap(arr[j], arr[j+1]);
        }
    }
    cout << "剩下的人是：" << arr[0] << endl;
}

int main()
{
    // josephus(8, 0, 3);
    // josephus(9, 1, 5);
    // josephus(9, 1, 0);
    josephus(9, 1, 10);
}