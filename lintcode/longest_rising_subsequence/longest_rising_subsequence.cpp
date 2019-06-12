#include "general.h"

int solve(vector<int> &nums, vector<int>& result)
{
    if(nums.size() == 0){
        return 0;
    }
    int f[nums.size()];
    f[0] = nums[0];
    int len = 0;
    for(int i = 0;i<nums.size();i++){
        if(nums[i] > f[len])
        {
            f[++len] = nums[i];
        }
        else
        {
            int j =lower_bound(f,f+len,nums[i])-f;
            f[j] = nums[i];
        }
    }
    return (len+1);
}

int main()
{
    vector<int> date = {1, 10, 11, 12, 2};
    vector<int> result;
    cout << solve(date, result);
}