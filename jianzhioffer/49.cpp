#include "general.h"

int GetUglyNumber(int index)
{
    if (index <= 0)
        return 0;

    vector<int> number;
    number.emplace_back(1);
    int thisIndex = 1;
    int max2 = 0;
    int max3 = 0;
    int max5 = 0;

    while(thisIndex < index){
        int minNum = std::min(number[max2] * 2, std::min(number[max3] * 3, number[max5] * 5));
        number.emplace_back(minNum);
        thisIndex++;
        for(int i = max2; i < number.size() && number[i] * 2 <= number.back(); ++i)
            max2 = i+1;
        for(int i = max3; i < number.size() && number[i] * 3 <= number.back(); ++i)
            max3 = i+1;
        for(int i = max5; i < number.size() && number[i] * 5 <= number.back(); ++i)
            max5 = i+1;
    }

    return number.back();
}

// ====================测试代码====================
void Test(int index, int expected)
{
    if(GetUglyNumber(index) == expected)
        printf("solution2 passed\n");
    else
        printf("solution2 failed\n");
}

int main(int argc, char* argv[])
{
    Test(1, 1);

    Test(2, 2);
    Test(3, 3);
    Test(4, 4);
    Test(5, 5);
    Test(6, 6);
    Test(7, 8);
    Test(8, 9);
    Test(9, 10);
    Test(10, 12);
    Test(11, 15);

    Test(1500, 859963392);

    Test(0, 0);

    return 0;
}