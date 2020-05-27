#include "general.h"

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int S = 3;

    auto size=nums.size();
    if(!size)
        return 0;
    vector<unordered_map<int,int>> dp(size);
    ++dp[0][nums[0]];
    ++dp[0][-nums[0]];
    for(auto i=1u;i<size;++i)
        for(auto it:dp[i-1]){
            dp[i][it.first+nums[i]]+=it.second;
            dp[i][it.first-nums[i]]+=it.second;
        }
    return dp[size-1][S];
}
