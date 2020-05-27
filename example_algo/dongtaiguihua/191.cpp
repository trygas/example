#include "general.h"

/*
 * 在第i位中,乘积最大的连续子序列要么是第i位数字本身,
 * 要么是前i-1位的乘积最大的连续子序列与第i位的积
 *
 * 只需一次遍历,在遍历时寻找从第0位到第i位乘积的最大值,
 * 但因为会存在负数,所以要同时寻找最小乘积,新的数也要乘以最小乘积进行比较
 */
int main()
{
    vector<int> nums = {1,2,-1,-2,2,1,-2,1,4,-5,4};

    int maxNum = nums[0], minNum = nums[0], result = nums[0];
    int n = nums.size();
    for(int i = 1; i < n; ++i){
        int maxTemp = maxNum, minTemp = minNum;
        maxNum = std::max(nums[i], std::max(nums[i] * maxTemp, nums[i] * minTemp));
        minNum = std::min(nums[i], std::min(nums[i] * maxTemp, nums[i] * minTemp));
        result = std::max(result, maxNum);
    }

    cout << result;
}
