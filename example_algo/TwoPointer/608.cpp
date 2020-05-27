#include "general.h"

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    int left = 0, right = nums.size() - 1;
    vector<int> res;
    while (left < right){
        int sum = nums[left] + nums[right];
        if(sum == target){
            res.push_back(left + 1);
            res.push_back(right + 1);
            break;
        }
        else if(sum < target){
            left++;
        }
        else{
            right--;
        }
    }

    PrintVector(res);
}