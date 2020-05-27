#include "general.h"

/*
 * 主要思路就是res[i] = min(res[i - nums[j]] + 1, res[i])
 */
int main()
{
    vector<int> nums = {21,31,51};
    int sum = 91;

    vector<int> res(sum + 1, 0);
    for(int i = 1; i <= sum; ++i ){
        res[i] = INT32_MAX;
        for(int j = 0; j < nums.size(); ++j){
            if(i - nums[j] >= 0 &&
               res[i - nums[j]] != INT32_MAX &&
               res[i - nums[j]] + 1 < res[i])
                res[i] = res[i - nums[j]] + 1;
        }
    }

    if (res[sum] == INT32_MAX)
        res[sum] = -1;

    PrintVector(res);
}
