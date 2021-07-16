#include <iostream>
#include <functional>
#include <random>

using namespace std;

// lambda表达式的形式 [captureClause](parameters) -> returnType {statements;}
// 其中[captureClause](parameters) 可以为空，"-> returnType" 可以省略(此时返回值用auto表示)。
// lambda 是 functor(一个类，只做一件事，重载()运算符)，因此可以像函数/函数指针一样使用。且回避了C++不支持嵌套函数的限制。

// 如何存储一个lambda表达式？
// 没有captureClause时，可以使用函数指针
// 不管有没有captureClause，都可以使用 std::functioin<returnType(parameters)> 和 auto(返回的是lambda的真实类型)

// auto 的好处在于开销比 std::functioin<returnType(parameters)> 小，但不是所有情况都适用。
// 比如，作为参数的时候，就不能用auto。
void repeat(int repetitions, const std::function<void(int)> &fn)
{
    for (int i{0}; i < repetitions; ++i)
    {
        fn(i);
    }
}

// lambdas 只能访问特定类型的标识符：全局标识符、编译时已知的实体和具有静态存储期的实体
// capture 子句用于给予 lambda 访问它通常无法访问的外层scope变量的访问权限。
// 捕捉到的变量默认会加上 const 修饰符。如果想在lambda内修改捕捉到的变量，需要在(parameters)后加 mutable 关键字。
// 捕捉到的变量默认是pass-by-value,要pass-by-reference需要在capture子句中的变量声明前加&。注意，如果pass-by-ref的变量在lambda之前引用失效了，会导致空引用。
// 可以捕捉多个变量，都现在capture子句中即可。甚至可以在capture子句定义新变量。
// [=]：捕捉所有用到的变量,pass-by-value
// [&]：捕捉所有用到的变量，pass-by-reference

// bind类似于 python/javascript 的 partial，偏函数。用于固定函数的某些参数。
void f(int n1, int n2, int n3, const int &n4, int n5)
{
    std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << '\n';
}

int g(int n1)
{
    return n1;
}

// bind 一个很好的用途是，使用类成员函数作为函数指针时，固定器第一个参数(即默认隐藏的 this)
class App
{
public:
    void OnEvent(int e)
    {
        cout << "OnEvent:" << e << endl;
    }
};

int main()
{
    using namespace std::placeholders;
    // repeat(3, [](int i)
    //        { std::cout << i << '\n'; });

    std::cout << "demonstrates argument reordering and pass-by-reference:\n";
    int n = 7;
    auto partial = std::bind(f, _2, 13, _1, std::cref(n), n);
    n = 42;
    partial(1, 2); // 第 n 个参数，对应占位符 std::placeholders::_n

    n = 7;
    std::cout << "achieving the same effect using a lambda:\n";
    auto lambda = [n=n, ncref = std::cref(n)](int n1, int n2){return f(n2, 13, n1, ncref, n);};
    n = 42;
    lambda(1, 2);

    std::cout << "nested bind subexpressions share the placeholders:\n";
    auto f2 = std::bind(f, _3, std::bind(g, _3), _3, 4, 5);
    f2(10, 11, 12); // 实际调用 f(12, g(12), 12, 4, 5),

    std::cout << "common use case: binding a RNG with a distribution:\n";
    std::default_random_engine e;
    e.seed(2);
    std::uniform_int_distribution<> d(0, 10);
    auto rnd = std::bind(d, e); // a copy of e is stored in rnd
    for (int n = 0; n < 10; ++n)
        std::cout << rnd() << ' ';
    std::cout << '\n';

    static App app;
    auto AppOnEvent = bind(&App::OnEvent, app, _1);
    AppOnEvent(8);
}