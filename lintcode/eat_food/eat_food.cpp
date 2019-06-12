#include <iostream>
#include <vector>

#include "general.h"

using namespace std;

int main()
{
    int number;
    int days;
    int kind;

    cin >> number >> days >> kind;

    vector<int> food_number;

    for (int i = 0; i < number; ++i)
    {
        int j;
        cin >> j;

        food_number.push_back(j);
    }

    PrintVector(food_number);

    for (int k = 0; k < days; ++k)
    {
        char choose;
        int kind;

        cin >> choose >> kind;

        if (choose == 'A')
            food_number[kind - 1] += 1;
        else if(choose == 'B')
            food_number[kind - 1] -= 1;
    }

    PrintVector(food_number);

    int order = 1;
    for (int l = 0; l < food_number.size(); ++l)
    {
        if(kind - 1 != l)
            continue;
        else if(food_number[kind - 1] > food_number[l])
            order += 1;
    }

    cout << order;
}
