#include "general.h"

int hIndex(vector<int> &citations)
{
    int sum = 0;
    vector<int> dp(citations.size() + 1, 0);

    for(int &i: citations){
        if(i > citations.size())
            sum++;
        else
            dp[i]++;
    }

    for(int i = dp.size() - 1; i >= 0; --i){
        sum += dp[i];
        if(sum >= i)
            return i;
    }

    return 0;
}

int main()
{
    vector<int> citations = {3, 0, 6, 1, 5};
    return hIndex(citations);
}
