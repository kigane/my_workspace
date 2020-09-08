#ifndef MY_UTILS
#define MY_UTILS
#include <iostream>
using namespace std;

const int DefaultSize = 10;

int ctoi(char c);
void printArr(int *arr, int sz);

template <class T>
struct LinkNode
{
    T data;
    LinkNode *link;
};

typedef LinkNode<int> Node;

template<class E>
class MinHeap
{
public:
    MinHeap(int sz = DefaultSize); // 建立空堆
    MinHeap(E arr[], int n); // 从给定的数组建立堆
    ~MinHeap() {delete [] heap;} // 析构函数
    bool Insert(const E& x); // 插入
    bool RemoveMin(E& x); // 删除堆顶元素
    bool IsEmpty()const { return (currSize == 0) ? true : false;}
    bool IsFull() const { return (currSize == maxHeapSize) ? true : false; }
    void MakeEmpty() {currSize = 0;}
    void Output()
    {
        E x;
        int n = currSize;
        for (int i = 0; i < n; i++)
        {
            RemoveMin(x);
            cout << x << endl;
        }
        
    }

private:
    E *heap;
    int currSize;
    int maxHeapSize;
    void siftDown(int start, int end);
    void siftUp(int start);
};

template <typename E>
MinHeap<E>::MinHeap(int sz)
{
    maxHeapSize = sz > DefaultSize ? sz : DefaultSize;
    heap = new E[maxHeapSize];
    currSize = 0;
}

template <typename E>
MinHeap<E>::MinHeap(E arr[], int n)
{
    maxHeapSize = n > DefaultSize ? n + 1 : DefaultSize;
    heap = new E[maxHeapSize]; //
    for (int i = 0; i < n; i++)
        heap[i + 1] = arr[i]; // heap[0] 空出来，利用树性质方便一点
    currSize = n;

    int currPos = (currSize + 1) / 2; // 堆当前处理的元素的指针 (heap[0]空着)
    while (currPos > 0)               // 从第一个非叶节点开始调整(偏序特性)。到根节点为止。
    {
        siftDown(currPos, currSize);
        currPos--;
    }
}

template <typename E>
void MinHeap<E>::siftUp(int start)
{
    int i = start;
    while (i > 0 && heap[i] < heap[i / 2]) // 若父节点更大，则修复
    {
        heap[0] = heap[i];
        heap[i] = heap[i / 2];
        heap[i / 2] = heap[0];
        i /= 2; // 继续向上调整
    }
}

template <typename E>
void MinHeap<E>::siftDown(int start, int end)
{
    int i = start, j = i * 2;
    heap[0] = heap[i];
    while (j <= end)
    {
        if (j < end && heap[j] > heap[j + 1]) // 比较两个子节点，选小的
            j++;
        if (heap[0] < heap[j]) // 如果偏序特性已经满足，就停止
            break;
        else
        {
            heap[i] = heap[j];
            i = j;  // 递归到子树
            j *= 2; // 到左子节点
        }
    }                  // 调整完毕
    heap[i] = heap[0]; // 调整起点的值归位
}

template <typename E>
bool MinHeap<E>::Insert(const E &x)
{
    if (currSize == maxHeapSize)
    {
        std::cerr << "Heap Full!" << std::endl;
        return false;
    }
    heap[currSize + 1] = x;
    siftUp(++currSize);
    return true;
}

template <typename E>
bool MinHeap<E>::RemoveMin(E &x)
{
    if (currSize == 0)
        return false;
    x = heap[1];
    heap[1] = heap[currSize];
    siftDown(1, --currSize);
    return true;
}
#endif