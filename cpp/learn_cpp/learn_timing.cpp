#include <iostream>
#include <chrono>

class Timer
{
public:
    Timer()
    {
        m_start = std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        auto end = std::chrono::high_resolution_clock::now();
        // microseconds 微秒 , milliseconds毫秒, 不做转型 nanoseconds 纳秒
        auto startTime = std::chrono::time_point_cast<std::chrono::microseconds>(m_start).time_since_epoch().count();
        auto endTime = std::chrono::time_point_cast<std::chrono::microseconds>(end).time_since_epoch().count();
        auto duration = endTime - startTime;
        std::cout << duration << "us\n";
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
};

int main ()
{
    {
        Timer timer;
        for (int i = 0; i < 1000; i++)
        {
            std::cout << "hello" << std::endl;
        }
    }
}