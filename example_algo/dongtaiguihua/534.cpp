#include "general.h"

/*
 * 主要思路就是要创建两个数组记录打劫区间[1,n-1]和[2,n]的获利情况.
 */
int main()
{
    vector<int> nums = {1,3,2,1,5};

    // res1代表不打劫最后一间房子, 则从第一所房子开始打劫
    vector<int> res1(nums.size(), 0);
    // res2代表打劫最后一间房子则从第二所房子开始打劫
    vector<int> res2(nums.size(), 0);
    for(int i = 0; i < nums.size() - 1; ++i){
        if(i == 0){
            res1[i] = nums[0];
        }
        if(i == 1){
            res1[i] = std::max(nums[1], res1[0]);
        }
        if(i > 1){
            res1[i] = std::max(res1[i - 2] + nums[i], res1[i - 1]);
        }
    }
    for(int i = 1; i < nums.size(); ++i){
        if (i == 1){
            res2[i - 1] = nums[1];
        }
        if (i == 2){
            res2[i - 1] = std::max(nums[2], res2[0]);
        }
        if (i > 2){
            res2[i - 1] = std::max(res2[i - 3] + nums[i], res2[i - 2]);
        }
    }

    PrintVector(res1);
    cout << endl;
    PrintVector(res2);
    return std::max(res1[nums.size() - 2], res2[nums.size() - 2]);
}