#include "general.h"

int maxProductAfterCutting_solution1(int length)
{
    if(length < 2)
        return 0;
    if(length == 2)
        return 1;
    if(length == 3)
        return 2;

    vector<int> products(length + 1, 0);
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;

    for(int i = 4; i <= length; ++i){
        for(int j = 1; j <= i / 2; ++j){
            products[i] = std::max(products[i], products[i - j] * products[j]);
        }
    }

    return products[length];
}

int main()
{
    cout << maxProductAfterCutting_solution1(10);
}