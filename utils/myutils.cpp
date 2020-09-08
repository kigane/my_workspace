#include "myutils.h"

int ctoi(char c)
{
    return c - '0';
}

void printArr(int *arr, int sz)
{
    std::cout << "[";
    for (int i = 0; i < sz - 1; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[sz - 1] << "]" << std::endl;
}

void createNodeList(int A[], int n, Node *&nodes)
{
    Node *p = nodes;
    for (int i = 0; i < n - 1; i++)
    {
        p->data = A[i];
        p->link = new Node;
        p = p->link;
    }
    p->data = A[n - 1];
    p->link = NULL;
}
