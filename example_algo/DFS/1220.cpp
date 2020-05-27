#include "general.h"

bool dfs(vector<int> &nums, int u, int cum, int start, int side,
         vector<bool> &visited)
{
    // 最终的评价标准还是要有四个相同的和
    if(u == 4)
        return true;
    if (cum == side)
        return dfs(nums, u + 1, 0, 0, side, visited);

    for(int i = start; i < nums.size(); ++i){
        if(visited[i] || cum + nums[i] > side)
            continue;

        visited[i] = true;
        if(dfs(nums, u, cum + nums[i], i + 1, side, visited))
            return true;
        visited[i] = false;

        while(i + 1 < nums.size() && nums[i + 1] == nums[i])
            i++;
        // 这个代码的含义是如果这些数据等于side,但是没有成功,则说明这个方案是错误的.
        if(!cum || cum + nums[i] == side)
            return false;
    }
}

int main()
{
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int sum = Sum(nums);

    if(sum % 4 != 0)
        return false;

    sort(nums.begin(), nums.end());
    for(auto num: nums){
        if(num > sum / 4)
            return false;
    }

    vector<bool> visited(nums.size());
    return dfs(nums, 0, 0, 0, sum / 4, visited);
}
