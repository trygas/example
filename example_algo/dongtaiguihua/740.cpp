#include "general.h"

int main()
{
    int amount = 8;
    vector<int> coins = {2, 3, 8};

    vector<int> res(amount + 1, 0);
    res[0] = 1;
    for(int i = 0; i < coins.size(); ++i){
        for(int j = coins[i]; j <= amount; ++j){
            res[j] += res[j - coins[i]];
        }
    }

    PrintVector(res);
}
