#include "general.h"

int findPairs(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int res = 0;

    for(int i = 0; i < nums.size(); ++i){
        while (i != 0 && i < nums.size() && nums[i] == nums[i - 1])
            ++i;
        int right = i + 1;
        while(right < nums.size() && nums[right] - nums[i] < k)
            right++;
        if(nums[right] - nums[i] == k)
            res++;
    }

    return res;
}

int main()
{
    vector<int> nums = {3, 1, 4, 1, 5};
    int k = 2;
    
    return findPairs(nums, k);
}