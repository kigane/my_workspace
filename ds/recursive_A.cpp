#include <iostream>
#include "myutils.h"
using namespace std;

int getMax(int A[], int n)
{
    if (n == 1)
        return A[0];
    return A[n-1] > getMax(A, n-1) ? A[n-1] : getMax(A, n-1);
}


int getSum(int A[], int n)
{
    if (n==1)
        return A[0];
    return A[n-1] + getSum(A, n-1);
}

double getAverage(int A[], int n)
{
    if (n == 1)
        return A[0];
    return (A[n-1] + getAverage(A, n-1)*(n-1))/n;
}

int getMax2(Node* head)
{
    if (head == NULL)
        return 0;
    if (head->link == NULL)
        return head->data;
    return head->data > getMax2(head->link) ? head->data : getMax2(head->link);
}

int getSum2(Node* head)
{
    if (head == NULL)
        return 0;
    if (head->link == NULL)
        return head->data;
    return head->data + getSum2(head->link);
}

double getAverage2(Node* head, int sz)
{
    if (head == NULL)
        return 0;
    if (head->link == NULL)
        return head->data;
    return (head->data + getAverage2(head->link, sz-1)*(sz-1))/sz;
}

int main(){
    int A[10] {4,3,2,1,7,6,5,9,8,0};
    Node *head = new Node;
    createNodeList(A, 10, head);
    cout << getAverage2(head, 10) << endl;
}