#include "general.h"

/*
 * 主要思路就是:
 * local[i][j] = Math.max(local[i - 1][j], global[i - 1][j - 1]) + nums[i - 1];
 * global[i][j] = Math.max(global[i - 1][j], local[i][j]);
 */
int handle(vector<int> &nums, int target)
{
    if(target > nums.size())
        return 0;

    vector<vector<int> > local(nums.size() + 1, vector<int>(target + 1));
    vector<vector<int> > global(nums.size() + 1, vector<int>(target + 1));

    for(int i = 1; i <= nums.size(); ++i){
        local[i][0] = INT32_MIN;
        for(int j = 1; j <= target; ++j){
            if (j > i){
                local[i][j] = INT32_MIN;
                global[i][j] = INT32_MIN;
                continue;
            }
            local[i][j] = std::max(local[i - 1][j], global[i - 1][j - 1]) + nums[i - 1];
            if (i == j)
                global[i][j] = local[i][j];
            else
                global[i][j] = std::max(local[i][j], global[i - 1][j]);
        }
    }

    return global[nums.size()][target];
}

int main()
{
    vector<int> nums = {5,-10,4};
    cout << handle(nums, 2);
}
