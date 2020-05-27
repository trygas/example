#include "general.h"

/*
 * 需要注意到这个里面两个for循环的顺序是很重要的
 * 这个题目nums可以复用，但是数字是不分顺序的，比如[2,3]和[3,2]都是一种
 * 所以这个题目要让nums的循环在外面
 */
int main(int argc, char *argv[])
{
    vector<int> nums = {2, 3, 6, 7};
    int target = 7;

    vector<int> res(target + 1, 0);
    res[0]=1;
    for(int i = 0; i < nums.size(); ++i){
        for(int j = nums[i]; j <= target; ++j){
                res[j] += (res[j - nums[i]]);
        }
    }

    PrintVector(res);
    return 0;
}
