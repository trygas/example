#include "general.h"

long long getSum(int n, vector<int> &nums)
{
    // write your code here
    if(nums.empty())
        return 0;
    int andmax = nums[0];
    int andmin = nums[0];
    int ormax = nums[0];
    int ormin = nums[0];

    for(int &i: nums){
        andmax = std::max(andmax, i);
        andmin = andmin & i;
        ormax = ormax | i;
        ormin = std::min(ormin, i);
    }

    return andmax + andmin + ormax + ormin;
}

int main()
{
    int n = 3;
    vector<int> nums = {1, 2, 3};

    return getSum(3, nums);
}
