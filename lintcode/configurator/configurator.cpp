#include <iostream>
#include <map>
#include "general.h"

using namespace std;

int main()
{
    Configurator configurator;
    int i;
    float j;

    configurator.Load("../configurator/configurator.txt");

    j = configurator.GetArgument("haha", 0);
    cout << j << endl;
}