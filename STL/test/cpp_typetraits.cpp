#include <iostream>

struct true_type
{
};
struct false_type
{
};

template<class type>
struct type_traits
{
    typedef true_type this_dummy_memeber_must_be_first;
    typedef false_type has_trivial_ctor;
};

template<> struct type_traits<long>
{
    typedef true_type has_trivial_ctor;
};

template<class T>
void test(T&)
{
    // 模板中依赖于模板参数的名称称为从属名称（dependent name, e.g. T::name）， 当一个从属名称嵌套在一个类里面时，称为嵌套从属名称（nested dependent name）。需要用typename来告诉编译器该名称不是变量，而是一个类型。
    test(typename type_traits<T>::has_trivial_ctor());
}

void test(true_type)
{
    std::cout << "dispatch to test with param true_type" << std::endl;
}

void test(false_type)
{
    std::cout << "dispatch to test with param false_type" << std::endl;
}

int main(){
    int a = 1;
    long b = 3;
    test(a);
    test(b);
}