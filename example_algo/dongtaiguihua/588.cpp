#include "general.h"

bool canPartition(vector<int> &nums)
{
    int len = nums.size();
    int sum = 0;
    for(int i = 0; i < len; ++i)
        sum += nums[i];
    if(sum % 2 == 1)
        return false;

    sum /= 2;
    int *dp = new int[20000];
    for(int i = 0; i <= sum; ++i)
        dp[i] = 0;
    dp[0] = 1;
    for(int i = 0; i < len; ++i){
        for(int j = sum; j >= nums[i]; --j)
            dp[j] |= dp[j - nums[i]];
    }

    return dp[sum];
}