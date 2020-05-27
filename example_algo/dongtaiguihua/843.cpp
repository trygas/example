#include "general.h"

/*
 * 主要思路就是定义两个数组
 * zero[i]代表第i位为0时最小翻转次数
 * one[i]代表第i位为1时最小翻转次数
 */
int main()
{
    vector<int> nums = {1, 0, 0, 1, 1, 1};

    vector<int> zero(nums.size() + 1, 0), one(nums.size() + 1, 0);

    for(int i = 1; i <= nums.size(); ++i){
        if (nums[i - 1] == 1){
            zero[i] = std::min(zero[i - 1] + 1, one[i - 1] + 1);
            one[i] = one[i - 1];
        }
        else{
            zero[i] = std::min(zero[i - 1], one[i - 1]);
            one[i] = one[i - 1] + 1;
        }
    }

    PrintVector(zero);
    PrintVector(one);
}