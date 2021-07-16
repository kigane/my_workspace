#include <iostream>
using namespace std;
#define BIT(x) (1 << x)

// 枚举类前置声明时，必须指定值类型(fixed base)。
enum Feeling : std::uint_least8_t;

// 定义枚举不占内存。当定义了某个枚举变量时，才为该枚举变量分配内存。和class,struct类似。
// 枚举成员必须命名，通常命名风格与常量相同。不推荐 ALL_CAPS 风格，因为可能会与预处理(preprocessor)宏名冲突。
// 枚举成员和枚举类是在同一个命名空间，即在同一命名空间中，相同的枚举成员名称会冲突。最好使用特殊前缀来区分。
// 枚举值，默认从 0 开始，按枚举顺序逐个 +1。
// 最佳实践，不要给枚举成员手动赋值。不要使用相同的枚举值。
enum Color
{
    red,
    green,
    blue,
};

// 枚举成员数值类型默认为 unsigned int。如果要设置为其他类型，需要在定义时指定。
enum Feeling : std::uint_least8_t
{
    happy,
    tired,
    f_blue
};

enum class Fruit
{
    apple,
    banana
};

enum class MobilePhone
{
    apple,
    huawei,
    xiaomi
};

// 唯一不用 class 比较好的情况。 
enum BitFlag
{
    success = 0,
    open_falied = BIT(0), 
    close_falied = BIT(1), 
    read_falied = BIT(2) 
};

// 枚举在 Debuger 中会出现
int main(){
    // 枚举初始化方式
    Color c1 = Color::red;
    Color c2(Color::red);
    Color c3{Color::blue};
    // Feeling f1{Feeling::blue}; // 编译不通过 
    Feeling f1{Feeling::f_blue};

    // 枚举成员可以作为数值输出，但反过来不行，除非使用类型转换。
    int v = Color::green;
    // Color c4 = 5; // 编译不通过
    // 输入一个数字，将其变为枚举，需要这样做
    // int num;
    // cin >> num;
    // Color c5 = static_cast<Color>(num);
    // cout << c5;

    // 不加 class 的枚举类型不安全。C++在处理枚举比较时，会隐式转化成整数后再比较的。
    if (Color::blue == Feeling::f_blue)
        cout << "wtf!!!!\n";
    else    
        cout << "Yes indeed"; 

    // 加了 class 的枚举在比较时，不会隐式转换成整数。但内部比较和不加 class 的枚举一致。
    // if (Fruit::apple == MobilePhone::apple) // 直接编译不通过
    MobilePhone mp {MobilePhone::xiaomi};
    if (mp > MobilePhone::huawei) 
        cout << "hello\n";
    else
        cout << "failed\n";
}