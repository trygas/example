#include <iostream>
#include <vector>

#include "general.h"

using namespace std;

bool helper(vector<int> &array, int position)
{
    if (position >= array.size() - 1)
        return 1;

    if (!array[position])
        return 0;

    for (int i = 1; i <= array[position]; ++i)
    {
        if (helper(array, position + i))
            return 1;
    }

    return 0;
}

int main()
{
    vector<int> array = {1, 0};

    cout << helper(array, 0);
}