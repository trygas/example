#include "general.h"

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    vector<int> dp(n + 1, INT32_MAX);

    dp[0] = 0;
    dp[1] = 0;
    if(n == 2)
        return std::min(cost[0], cost[1]);

    for(int i = 2; i <= n; ++i){
        dp[i] = std::min(dp[i - 1] + cost[i - 1], dp[i]);
        dp[i] = std::min(dp[i - 2] + cost[i - 2], dp[i]);
    }

    return dp[n];
}

int main()
{
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << minCostClimbingStairs(cost);
}