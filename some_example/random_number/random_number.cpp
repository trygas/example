#include <ctime>
#include <iostream>
#include <cstdlib>

#define random(a, b) (rand() % (b - a + 1) + a)

int main()
{
    srand((unsigned)time(NULL));

    for(int i = 0; i < 10; ++i)
    {
        std::cout << random(0, 100) << std::endl;
    }
    
    return 0;
}