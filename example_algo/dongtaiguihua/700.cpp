#include "general.h"

/*
 * 主要思路就是要构建一个数组res
 * res[i]代表i尺寸最大碎片价格
 * 然后i+1的时候遍历0到i的尺寸, 算出最大的.
 */
int main()
{
    vector<int> nums = {1, 5, 8, 9, 10, 17, 17, 20};
    int target = 8;

    vector<int> res(nums.size() + 1, 0);
    for(int i = 1; i <= nums.size(); ++i){
        for(int j = 1; j <= i; ++j){
            res[i] = std::max(res[i], nums[j - 1] + res[i - j]);
        }
    }

    PrintVector(res);
}
