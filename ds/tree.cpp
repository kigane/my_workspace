#include <iostream>
#include <cstring>
#include <fstream>
#include <stack>
using namespace std;

typedef struct BiTNode
{
    int value;
    BiTNode *lchild = NULL, *rchild = NULL;
} BiTNode, *BiTree;

int ctoi(char);
BiTNode* createBiTreeFromGList(string);
BiTNode *createBiTreeFromText(); // 由广义表字符串构造树
void preOrder(BiTree); // 递归前序遍历
void preOrderStack(BiTree); // 前序遍历
void traverseStack(BiTree); // 前中序遍历的另一种写法 
int treeSize(BiTree); // 求树的节点数
int treeHeight(BiTree); // 求树高
bool treeEqual(BiTree, BiTree); // 判断两棵树是否相同

int main()
{
    string tree = "1(2(4,5),3(6(8,9),7))#";
    BiTree t = NULL, t2 = NULL;
    t2 = createBiTreeFromGList(tree);
    t = createBiTreeFromText();
    cout << treeEqual(t, t2) << endl;
}

int treeHeight(BiTree root)
{
    if (root == NULL)
        return 0;
    else
    {
        int i = treeHeight(root->lchild);
        int j = treeHeight(root->rchild);
        return max(++i, ++j);
    }
}

bool treeEqual(BiTree t1, BiTree t2)
{
    if (t1 == NULL && t2 == NULL)
        return true;
    if (treeEqual(t1->lchild, t2->lchild) && treeEqual(t1->rchild, t2->rchild) && t1->value == t2->value)
        return true;
    else
        return false;
}

int treeSize(BiTree root)
{
    if (root == NULL)
        return 0;
    return 1 + treeSize(root->lchild) + treeSize(root->rchild);
}

// 前序遍历二叉树
void preOrder(BiTree t)
{
    if (t != NULL)
    {
        cout << t->value << endl;
        preOrder(t->lchild);
        preOrder(t->rchild);
    }
}

void preOrderStack(BiTree t)
{
    stack<BiTree> s;
    BiTree p = t;
    while (p != NULL || !s.empty()) // 根节点为空直接退，栈为空即遍历完成退, 取出栈中最后一个元素后继续
    {
        if (p != NULL) // 向左走到尽头 (从根开始 | 向右一步，节点不为空)
        {
            cout << p->value << endl; // 先序访问数据位置
            s.push(p);
            p = p->lchild;
        }
        else
        {
            p = s.top(); // 回退一层
            s.pop();
            // cout << p->value << endl; // 中序位置
            p = p->rchild; // 向右走一步
        }   
    }
}

void traverseStack(BiTree root)
{
    stack<BiTree> s;
    BiTree p = root;

    do
    {
        while (p != NULL) // 向左走到尽头 (从根开始 | 向右一步，节点不为空)
        {
            // cout << p->value << endl; // 先序访问数据位置
            s.push(p);
            p = p->lchild;
        }

        if (!s.empty()) // 回退一层
        {
            p = s.top();
            s.pop();
            cout << p->value << endl; // 中序访问数据位置
            p = p->rchild;            // 向右走一步
        }
    } while (p != NULL || !s.empty()); // 根节点为空直接退，栈为空即遍历完成退
}

int ctoi(char c)
{
    return c - '0';
}

// 从广义表建立二叉树
BiTNode *createBiTreeFromGList(string gl)
{
    int k = 0;
    BiTree p = NULL, root = NULL;
    stack<BiTree> s;

    for (int i = 0; i < (int)gl.length(); i++)
    {
        switch (gl[i])
        {
        case '(':
            k = 0;
            s.push(p);
            break;
        case ')':
            s.pop();
            break;
        case ',':
            k = 1;
            break;
        case '#':
            return root;
        default:
            p = new BiTNode;
            p->value = ctoi(gl[i]);
            if (root == NULL)
                root = p;
            else if (k == 0)
                s.top()->lchild = p;
            else if (k == 1)
                s.top()->rchild = p;
        }
    }
    return root;
}

BiTNode *createBiTreeFromText()
{
    string path = "gltree.txt";
    ifstream fs(path.c_str());
    int k = 0, val;
    char ch;
    BiTree p = NULL, root = NULL;
    stack<BiTree> s;

    while (!fs.eof())
    {
        ch = fs.get();
        switch (ch)
        {
        case '(':
            k = 0;
            s.push(p);
            break;
        case ')':
            s.pop();
            break;
        case ',':
            k = 1;
            break;
        case '#':
            return root;
        default:
            fs.putback(ch);
            fs >> val;
            p = new BiTNode;
            p->value = val;
            if (root == NULL)
                root = p;
            else if (k == 0)
                s.top()->lchild = p;
            else if (k == 1)
                s.top()->rchild = p;
        }
    }
    fs.close();
    return root;
}