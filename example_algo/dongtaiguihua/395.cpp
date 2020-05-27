#include "general.h"

/*
 * 构建一个数组res, 从最后开始计算
 * res[i]代表从i到最后一个元素能取到的最大值
 */
int main()
{
    vector<int> nums = {1, 2, 2};

    int sum = 0;
    int n = nums.size();
    vector<int> res(nums.size(), 0);

    if (n < 3)
        return true;

    res[n] = 0;
    res[n - 1] = nums[n - 1];
    res[n - 2] = nums[n - 1] + nums[n - 2];
    res[n - 3] = nums[n - 2] + nums[n - 3];
    sum = nums[n - 1] + nums[n - 2] + nums[n - 3];

    for(int i = n - 4; i >= 0; --i){
        int a = nums[i] + std::min(res[i + 2], res[i + 3]);
        int b = nums[i] + nums[i + 1] + std::min(res[i + 3], res[i + 4]);
        res[i] = std::max(a, b);
        sum += nums[i];
    }

    return res[0] > sum - res[0];
}
