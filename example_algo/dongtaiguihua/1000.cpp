#include "general.h"

int main()
{
    vector<int> prices = {1, 4, 6, 2, 8, 3, 10, 14};
    int fee = 3;

    int n = prices.size();
    vector<int> hold(n, 0);
    vector<int> sell(n, 0);
    hold[0] = -prices[0];
    for(int i = 1; i < n; ++i){
        hold[i] = std::max(hold[i - 1], sell[i - 1] - prices[i]);
        sell[i] = std::max(sell[i - 1], hold[i - 1] + prices[i] - fee);
    }

    PrintVector(sell);
}
