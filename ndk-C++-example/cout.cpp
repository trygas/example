#include "cout.h"

int coutHelloworld()
{
    return 1;
}

std::string changeString(std::string originString)
{
    originString.clear();
    originString = "newString";
    return originString;
}

std::vector<double> changeVectorDouble(std::vector<double> &someNum)
{
    someNum.clear();
    someNum.push_back(3.141592653);
    return someNum;
}

std::vector<double> generateVectorDouble()
{
    std::vector<double> newVector = {1, 2, 3};
    return newVector;
}
