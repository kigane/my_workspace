#include <iostream>
#include <memory>
#include <string>
using namespace std;

struct AllocationMetrics
{
    uint32_t TotalAllocated = 0;
    uint32_t TotalFreed = 0;
    uint32_t CurrentUsage() {return TotalAllocated - TotalFreed;}
};

static AllocationMetrics s_AllocationMetrics;

void* operator new(size_t size)
{
    s_AllocationMetrics.TotalAllocated += size;
    return malloc(size);
};

void operator delete(void* memory, size_t size)
{
    s_AllocationMetrics.TotalFreed += size;
    free(memory);
}

static void PrintUsage()
{
    std::cout << s_AllocationMetrics.CurrentUsage() << std::endl;
}

class Object
{
    int x, y, z;
};


int main(){
    // MinGW 是 0, 0, 12, 0 ||| MSVC 是 0, 8, 20, 8
    PrintUsage();
    std::string str = "Hazel Engine";
    PrintUsage();
    {
        std::unique_ptr<Object> obj = make_unique<Object>();
        PrintUsage();
    }
    PrintUsage();
}