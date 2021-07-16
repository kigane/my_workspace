#include <iostream>
using namespace std;
#define PRINT(x) cout << (x) << endl
#define PRINT_HEX_8(x) printf("0x%08X\n", x)
#define PRINT_HEX_2(x) printf("0x%02X\n", x)
#define PRINT_BIN(x) cs00::IntToBinary(x)

// 工具函数
namespace cs00
{
    void IntToBinary(unsigned int k)
    {
        if (k == 0)
            printf("0\n");
        else if (k == 2)
            printf("10\n");
        else
        {
            char b[33] {};
            int i = -1;
            while (k > 0)
            {
                b[++i] = (k % 2) + '0';
                k /= 2;
            }
            for (int j = 0; j < i / 2; ++j)
                swap(b[j], b[i - j]);
            printf("%s\n", b);
        }
    }

    unsigned int ToBinary(unsigned int k)
    {
        // 最大 1023
        return (k == 0 || k == 1 ? k : ((k % 2) + 10 * ToBinary(k / 2)));
    }

    unsigned Float2Unsign(float f)
    {
        union
        {
            float f;
            unsigned u;
        } tmp;
        tmp.f = f;
        return tmp.u;
    }
} // namespace cs00

namespace cs01
{
    void EndianTest()
    {
        union NUM
        {
            int a;
            char b;
        } num;
        num.a = 0x12345678;
        if (num.b == 0x12)
            PRINT("大端序");
        else
            PRINT("小端序");
        printf("b = 0x%X\n", num.b); // 小端序
    }

    void FloatPrecisionTest()
    {
        float x;
        x = 61.42;
        cout.setf(ios::fixed, ios::floatfield);
        PRINT(x);
    }
} // namespace 01

namespace cs02
{
    void OverflowTest()
    {
        unsigned int x = 3;
        unsigned int y = 4;
        unsigned int result;
        result = x - y;
        if (x < y)
            PRINT(result);
    }
} // namespace cs02

namespace cs03
{
    void FloatDivideByZero()
    {
        float x = 1.0, y = -1.0, z = 0.0;
        printf("x/z=%f, y/z=%f\n", x/z, y/z);
    }

    void FloatRound()
    {
        float a = 123456.789e4;
        double b = 123456.789e4;
        printf("%f\n%f\n", a, b);
    }
} // namespace cs03

namespace cs04
{

} // namespace cs04

class Entity
{
public:
    Entity(int a) {PRINT("Entity Constructor called");}
    ~Entity() {PRINT("Entity Destructor called");}
    void DoSomething()
    {
        PRINT("something had done");
    }
};

#include <memory>
#include <unordered_map>
#include <string>

int main()
{
    // cs01::EndianTest();
    // cs01::FloatPrecisionTest();
    // cs02::OverflowTest();
    // cs03::FloatDivideByZero();
    // cs03::FloatRound();
    // PRINT(cs00::Float2Unsign(10.0));
    char str[] {'s', 'm', 'k'};
    char* cstr = str;
    string s = cstr;
    PRINT(cstr);
    PRINT(s);
}