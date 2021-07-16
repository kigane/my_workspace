#include <iostream>
#include <typeinfo>
#include <string>
float na = 1;
class foo 
{
public:
    virtual void FooFunc() {};
    void func() { na = 9;};
    int na; // 16
private:
    int nb; // 16
    int nc; // 24
    int nd; // 24
    int ne; // 32
};

int main(){
    std::cout << sizeof(int) << "\n";
    std::cout << sizeof(foo) << "\n";
}