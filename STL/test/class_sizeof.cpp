#include <iostream>
using namespace std;

class X
{
public:
    X(){cout << "X constructor\n";};
    int xa;
};

class Y : public virtual X
{
public:
    Y() { cout << "Y constructor\n"; };
};

class Z : public virtual X
{
public:
    Z() { cout << "Z constructor\n"; };
};

class A : public Y, public Z
{
public:
    A() { cout << "A constructor\n"; };
};

int main()
{
    // 当 X 是空类时
    // cout << sizeof(X) << endl; // 1 byte 使该类产生的两个对象能在内存中配置独一无二的地址
    // // 这里使用的编译器对 Empty virtual base class 有优化，其派生类无需插入额外的 1 byte
    // cout << sizeof(Y) << endl; // bvtr 指向虚基类的指针在64位系统上为 8 byte
    // cout << sizeof(Z) << endl; // 同上
    // cout << sizeof(A) << endl; // Y + Z

    // 当 X 只有一个 int 变量
    Y y;
    Z z;
    A a;
    cout << sizeof(X) << endl; // 4 byte
    cout << sizeof(Y) << endl; // vbtr 指向虚基类的指针为 8 byte, 加上 X 的大小 4 byte，加上 4 byte padding 对齐
    cout << sizeof(Z) << endl; // 同上
    cout << sizeof(A) << endl; // Y + Z，其中 X 只构造一次
}