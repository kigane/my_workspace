#include <iostream>
#include <cstdlib> // for std::rand() and std::srand()
#include <ctime> // for std::time()
#include "effolkronium/random.hpp"

// 线性同余法
unsigned int PRNG() // pseudo-random number generator
{
    static unsigned int seed{5323};
    seed = 8253729 * seed + 2396403;
    return seed % 32768;
}

void PrintNumbersWithPRNG()
{
    // 打印 100 个数
    for (int count{1}; count <= 100; ++count)
    {
        std::cout << PRNG() << '\t';

        if (count % 5 == 0)
            std::cout << '\n';
    }
}

void PrintNumbersWithRand()
{
    std::srand(5323);
    // 因为某些编译器中rand算法的缺陷，导致第一个随机数大概率相同，所以这里先调用一次
    std::rand();

    // 打印 100 个数
    for (int count{1}; count <= 100; ++count)
    {
        std::cout << std::rand() << '\t';

        if (count % 5 == 0)
            std::cout << '\n';
    }
}

void PrintNumbersWithDiffSeeds()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::rand();

    for (int count{1}; count <= 100; ++count)
    {
        std::cout << std::rand() << '\t';

        if (count % 5 == 0)
            std::cout << '\n';
    }
}

int main()
{
    // PrintNumbersWithPRNG();
    // PrintNumbersWithRand();
    // PrintNumbersWithDiffSeeds();
    // std::cout << effolkronium::random_static::get(1,6);
    for (int i = 0; i < 10; i++)
        printf("%d\n", i%4);
}