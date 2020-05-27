#include "general.h"

/*
 * 这个题的思路就是建立一个二维数组,res[i][j]
 * res[i][j]表示为前i个数字中相加为j的数字的组合.
 */
int main()
{
    vector<int> nums = {1, 2, 4};
    int target = 4;

    vector<vector<int > > res(nums.size() + 1, vector<int>(target + 1, 0));
    for(int i = 0; i <= nums.size(); ++i)
        res[i][0] = 1;
    for(int i = 1; i <= nums.size(); ++i){
        for(int j = 1; j <= target; ++j){
            for(int k = 0; k < i; ++k){
                if (j - nums[k] >= 0){
                    res[i][j] += res[i][j - nums[k]];
                }
            }
        }
    }

    PrintVectorVector(res);
}
