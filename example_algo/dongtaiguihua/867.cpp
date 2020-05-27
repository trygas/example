#include "general.h"

/*
 * 获得最优解的按键序列一定可以用以下两种子序列拼接而成
 * 1. 数个连续的A
 * 2. CA + CC + 连续数个的CV
 */
int main()
{
    int N = 7;

    vector<int> dp(N + 1, 0);
    for(int i = 1; i <= N; ++i){
        dp[i] = dp[i - 1] + 1;
        for(int j = 1; j + 2 < i; ++j){
            dp[i] = std::max(dp[i], dp[i - 2 - j] * (j + 1));
        }
    }

    cout << dp[N];
}