#include <iostream>
#include <vector>
using namespace std;

class IDGenerator
{
private:
    static int ID; // 声明 declaration
public:
    void func()
    {
        cout << ID; // non-static function 可以访问 private static member variables，但不推荐
    }

    static int  GetId() // 最好是用static function来访问，这样不需要类对象就可以使用类功能。
    {
        return ID++;
    }
};

int IDGenerator::ID = 1; // 定义 definition

// 当 private static member variable 需要比较复杂的初始化时该怎么办？
// 第一种方法，定义lambda并立即使用
class MyClass
{
private:
    static vector<char> chs; 
public:
    static void PrintChs()
    {
        for (auto v : chs)
            cout << v << ' ';
    }
};

vector<char> MyClass::chs = [](){
    vector<char> tmp;
    for (char ch = 'a'; ch <= 'z'; ++ch)
        tmp.push_back(ch);
    return tmp;    
    }();

// 第二种方法，定义一个内部类和相应类型的static变量用于初始化
class TrickyClass
{
public:
    static void PrintChs()
    {
        for (auto v : chs)
            cout << v << ' ';
    };
    class init_static // we're defining a nested class named init_static
    {
    public:
        init_static() // the init constructor will initialize our static variable
        {
            for (char ch{'a'}; ch <= 'z'; ++ch)
            {
                chs.push_back(ch);
            }
        }
    };
private:
    static vector<char> chs;
    static init_static s_Initializer;
};

std::vector<char> TrickyClass::chs{};              // 定义
TrickyClass::init_static TrickyClass::s_Initializer{}; // 定义s_Initializer,将会调用init_static的构造器来初始化chs

int main(){
    for (int i = 0; i < 6; i++)
    {
        cout << IDGenerator::GetId() << ' ';
    }
    cout << endl;

    MyClass::PrintChs();
    cout << endl;

    TrickyClass::PrintChs();
}