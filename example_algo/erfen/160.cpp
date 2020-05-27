#include "general.h"

int findMin(vector<int> &nums) {
    // write your code here
    int left = 0, right = nums.size() - 1;

    while(left + 1 < right){
        while(nums[left + 1] == nums[left])
            left++;
        while(nums[right - 1] == nums[right])
            right--;
        if(left + 1 > right)
            break;
        int mid = (left + right) / 2;
        if(nums[mid] > nums[left] && nums[mid] > nums[right])
            left = mid;
        else
            right = mid;
    }

    return std::min(nums[left], nums[right]);

}


int main()
{
    vector<int> nums = {3, 1, 1, 1, 3};

    cout << findMin(nums);
}
