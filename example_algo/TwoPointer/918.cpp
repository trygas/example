#include "general.h"

int threeSumSmaller(vector<int> &nums, int target) {
    // Write your code here
    int ans = 0;
    sort(nums.begin(), nums.end());
    int len = nums.size();
    for(int i = 0; i < len - 2; i++) {
        int left = i + 1, right = len - 1;
        while(left < right) {
            if(nums[i] + nums[left] + nums[right] < target) {
                ans += right-left;
                left++;
            } else {
                right--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {-2, 0, -1, 3};
    int target = 2;

    cout << threeSumSmaller(nums, target);
}
