#include <algorithm>
#include <vector>
#include <functional>
#include <iostream>

using namespace std;

void useSixComponents()
{
    int ia[]{21, 43, 45, 67, 8, 97};
    vector<int, allocator<int>> vi(ia, ia + 6);
    cout << count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(), 40))) << endl;
}

#define SHOW_CONTENT(desc, k)                         \
    cout << desc << "[";                              \
    for (auto ite = k.begin(); ite != k.end(); ++ite) \
        cout << *ite << ", ";                         \
    cout << "]" << endl;

// template<typename T, template<typename T> class K>
// void show_content(const K<T>& k)
// {
//     for (auto ite = k.begin(); ite != k.end(); ++ite)
//         cout << " " << *ite;
//     cout << endl;
// }

long get_a_long_target()
{
    long target = 0;
    cout << "target (0~" << RAND_MAX << "):";
    cin >> target;
    return target;
}

string get_a_string_target()
{
    long target = 0;
    char buf[10];
    cout << "target (0~" << RAND_MAX << "):";
    cin >> target;
    snprintf(buf, 10, "%d", target);
    return string(buf);
}

int compareLong(const void* a, const void* b)
{
    return (*(long*)a - *(long*)b);
}

int compateString(const void* a, const void* b)
{
    if (*(string*)a > *(string*)b)
        return 1;
    else if (*(string*)a < *(string*)b)
        return -1;
    else 
        return 0;
}

#include <cstdio> //qsort,bsearch
#include <iostream>
#include <ctime>
#include <array>
namespace hwk01
{
const int ASIZE = 500000;
void test_array()
{
    cout << "test_array()...start" << endl;
array<int, ASIZE> ary;
clock_t startTime = clock();
    for (int i = 0; i < ASIZE; i++)
    {
        ary[i] = rand();
    }
    cout << "milli-seconds:" << (clock() - startTime) << endl;
    cout << ary.size() << endl;
    cout << ary.front() << endl;
    cout << ary.back() << endl;
    cout << ary.data() << endl; // 相当与&ary

long target = get_a_long_target();
    startTime = clock();
    qsort(ary.data(), ASIZE, sizeof(long), compareLong);
    long* pItem = (long *)bsearch(&target, ary.data(), ASIZE, sizeof(long), compareLong);
    cout << "milli-seconds:" << (clock() - startTime) << endl;
    if (pItem != NULL)
        cout << "found " << *pItem << endl;
    else    
        cout << "not found" << endl;
    cout << "test_array()...end" << endl;
}
} // namespace hwk01

#include <iostream>
#include <ctime>
#include <cstdlib> // abort()
#include <cstdio> // snprintf()
#include <algorithm> // sort()
#include <vector>
#include <string>
#include <stdexcept>
namespace hwk02
{
void test_vector()
{
int ASIZE = 10000000;
    cout << "test_vector()...start" << endl;

vector<string> c;
char buf[10];
clock_t startTime = clock();
    for (long i = 0; i < ASIZE; i++)
    {
        try
        {
            snprintf(buf, 10, "%d", rand());
            c.push_back(string(buf));
        }
        catch(const std::exception& e)
        {
            // ASIZE = 1000000000 时出错 i = 536870912 std::bad_alloc
            std::cerr << "i = " << i << " " << e.what() << '\n';
            abort();
        }
    }
    cout << "milli-seconds:" << (clock() - startTime) << endl;
    cout << c.size() << endl;
    cout << c.front() << endl;
    cout << c.back() << endl;
    cout << c.data() << endl;
    cout << c.capacity() << endl;
    cout << c.max_size() << endl;
    cout << "test_vector()...end" << endl;
}  
} // namespace hwk02

#include <vector>
namespace hwk03
{
    const int ASIZE = 6;
    void array_test()
    {
        // 构造器: 和 int[] 一样
        array<double, ASIZE> ary {1.2, 1.5, 2.3, 3.6, 3.7, 11.2};

        // 迭代器
        cout << "iterator...begin..end" << endl;
        for (auto ite = ary.begin(); ite != ary.end(); ++ite)
            cout << *ite << endl;

        cout << endl << "iterator...rbegin..rend" << endl;
        for (auto ite = ary.rbegin(); ite != ary.rend(); ++ite)
            cout << *ite << endl;

        auto c_ite = ary.cbegin();
        // 不允许 *c_ite = 6.6;

        // 取值
        cout << endl << "access elements...front..back" << endl;
        double first = ary.front();
        double last = ary.back();
        double fifth = ary.at(4);
        ary[3] = 6.6;
        double fourth = ary[3];
        cout << "ary.front(): " << first << endl;
        cout << "ary.back(): " << last << endl;
        cout << "ary.at(4): " << fifth << endl;
        cout << "ary[3]: " << fourth << endl;

        // 容量
        cout << endl << "capacity...size..empty" << endl;
        cout << "ary.size(): " << ary.size() << endl;
        cout << "ary.max_size(): " << ary.max_size() << endl;
        cout << "ary.empty(): " << ary.empty() << endl;

        // 其他
        cout << "ary.data(): " << ary.data() << endl;
        array<double, ASIZE> x {11.1, 22.2, 33.3};
        ary.swap(x);
        for (int i = 0; i < ASIZE; ++i)
            cout << ary.at(i) << endl;
    }
} // namespace hwk03

namespace hwk04
{
    void vector_test()
    {
        // 构造器
        // initializer list
    vector<double> v {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
        // default
    vector<double> first; // empty vector of double
        // fill
    vector<double> second1(5); // 5 个 0.0
    vector<double> second2(4, 9.9); // 4 个 9.9
        // range
    vector<double> third1(v.begin() + 1, v.end() - 1); // v中间四个数
        double data[] = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
    vector<double> third2(data, data + 6);
        // copy
    vector<double> fourth(third1); // 和third相同

        // 迭代器
        cout << "iterator...begin..end" << endl;
        SHOW_CONTENT("now Vector second1:", second1);

        cout << endl << "iterator...rbegin..rend" << endl;
        SHOW_CONTENT("now Vector fourth reverse order:", fourth);

     auto c_ite = v.cbegin();
        // 不允许 *c_ite = 6.6;

        // 取值
        cout << endl << "access elements...front..back" << endl;
    double vfirst = v.front();
    double vlast = v.back();
    double vfifth = v.at(4);
    double vfourth = v[3];
        cout << "v.front(): " << vfirst << endl;
        cout << "v.back(): " << vlast << endl;
        cout << "v.at(4): " << vfifth << endl;
        cout << "v[3]: " << vfourth << endl;

        // 容量
        cout << endl << "capacity...size..empty..capacity......" << endl;
        cout << "v.size(): " << v.size() << endl;
        cout << "v.capacity(): " << v.capacity() << endl; // vector独有
        cout << "v.max_size(): " << v.max_size() << endl;
        v.reserve(30); // vector 独有
        cout << "v.reserve(30)后v.capacity(): " << v.capacity() << endl;
        // resize
        v.resize(5);
        cout << "v.resize(5)后v.size(): " << v.size() << endl;
        SHOW_CONTENT("now Vector v:",v);
        v.resize(8);
        cout << "v.resize(8)后v.size(): " << v.size() << endl;
        SHOW_CONTENT("now Vector v:", v);
        v.resize(10, 7.7);
        cout << "v.resize(10, 7.7)后v.size(): " << v.size() << endl;
        cout << "resize()不会影响capacity除非n>capacity v.capacity(): " << v.capacity() << endl;
        SHOW_CONTENT("now Vector v:", v);
        v.shrink_to_fit();
        cout << "v.shrink_to_fit()后v.capacity(): " << v.capacity() << endl;

        // 修改 Modifiers
        // assign 删除当前所有元素，用assign指定的值重新确定容器内容和size。
        cout << "Modifiers...assign..insert..erase..push_back......" << endl;
        v.assign({1,2,3,6.6});
        SHOW_CONTENT("now Vector v:", v);
        v.assign(6, 6.6);
        SHOW_CONTENT("now Vector v:", v);
        v.assign(data + 1, data + 5);
        SHOW_CONTENT("now Vector v:", v);
        v.assign(second2.begin(), second2.end());
        SHOW_CONTENT("now Vector v:", v);

        // insert
        v.insert(v.begin() + 1, 8.8); // 在指定位置添加单个元素
        SHOW_CONTENT("now Vector v:", v);
        v.insert(v.begin() + 1,data, data+2); // range 添加一段
        SHOW_CONTENT("now Vector v:", v);
        v.insert(v.end() - 1, 3, 4.4); // fill 在指定位置添加几个相同元素
        SHOW_CONTENT("now Vector v:", v);

        // emplace 在指定位置高效添加单个元素，位置参数之后的参数都会传给构造器，构造器创造一个对象添加到指定位置。因此不会产生临时对象。
        v.emplace(v.begin() + 1, 3.14);
        v.emplace_back(2.718); // 在容器尾部添加单个元素
        SHOW_CONTENT("now Vector v:", v);

        // erase 
        v.erase(v.begin() + 1); // single 单点删除
        SHOW_CONTENT("now Vector v:", v);
        v.erase(v.begin() + 1, v.begin() + 4); // range 删除一段
        SHOW_CONTENT("now Vector v:", v);

        // push_back, pop_back 略
        
        // clear
        v.clear();
        cout << "v.clear()清空容器后v.empty()：" << v.empty() << endl;
        v.swap(second1);
        SHOW_CONTENT("now Vector v:", v);
        SHOW_CONTENT("now Vector second1:", second1);
    }
} // namespace hwk04

#include <list>
namespace hwk05
{
    void list_test()
    {
        // 基本操作类似 vector 略
        // list operations 
        // PS:list的内存不是连续的不支持 ite+i 操作，++/--还是支持的。
        cout << "list operations...splice..unique..sort..merge..remove..remove_if..reverse" << endl;
    list<double> li({1.1, 1.2, 2.3, 3.1, 3.14, 4.4, 9.6});
    list<double> tli(3, 6.6);

        // splice
        li.splice(li.begin(), tli);
        SHOW_CONTENT("now list li:", li);
        SHOW_CONTENT("now list tli:", tli);
    auto ite = li.end();
        ite--; // 指向 9.6
        tli.splice(tli.begin(), li, ite); // single
        SHOW_CONTENT("now list tli:", tli);
        SHOW_CONTENT("now list li:", li);
        ite = li.begin();
        std::advance(ite, 2); // 相当于 ++ 3次
        // 把第3个到最后一个元素剪切到最前面
        li.splice(li.begin(), li, ite, li.end()); // range 
        SHOW_CONTENT("now list li:", li);

        // sort
        li.sort();
        SHOW_CONTENT("now list li:", li);

        // unique 前一个元素和后一个元素比较，如果相同，则移除后一个元素
        li.unique(); // default 比较方法
        SHOW_CONTENT("now list li:", li);
        li.unique([](double a, double b)->bool {return (int)a == (int)b;}); // 自定义比较是否相同方法，需要返回一个bool值
        SHOW_CONTENT("now list li:", li);

        // merge 将被合并的list中所有元素添加到接受合并的list的符合顺序的位置上。
        li.merge(tli);
        SHOW_CONTENT("now list li:", li);
        list<double> cli {3.1, 7.7, 9.1};
        cli.sort();
        li.merge(cli, [](double a, double b) -> bool { return (int)a < (int)b; }); // 自定义比较是否相同方法，需要返回一个bool值
        SHOW_CONTENT("now list li:", li);
        SHOW_CONTENT("now list cli:", cli);

        // remove
        li.remove(3.1); // 删除所有指定值
        SHOW_CONTENT("now list li:", li);
        li.remove_if([](double x) -> bool { return x < 3.14; });
        SHOW_CONTENT("now list li:", li);

        // reverse
        li.reverse();
        SHOW_CONTENT("now list li:", li);
    }
} // namespace hwk05

namespace hwk06
{
    void set_test()
    {
        
    }
} // namespace hwk06



int main()
{
    // useSixComponents();
    // hwk01::test_array();
    // hwk02::test_vector();
    // hwk04::vector_test();
    // hwk05::list_test();
}