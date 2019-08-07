#include <iostream>
#include "cout.h"

using namespace std;

int main()
{
    std::string thisString = "12";
    cout << thisString << endl;
    std::string newString = changeString(thisString);
    cout << newString << endl;
    std::vector<double> thisVector = generateVectorDouble();
    for (int i = 0; i < thisVector.size(); ++i)
    {
        cout << thisVector[i] << " ";
    }
    cout << endl;
    changeVectorDouble(thisVector);
    for (int i = 0; i < thisVector.size(); ++i)
    {
        cout << thisVector[i] << " ";
    }
    cout << endl;
}