#include "general.h"

int findPosition(vector<int>& nums, int target, bool left) {
    int start = 0, end = nums.size() - 1;
    while(start + 1 < end) {
        int mid = start + (end - start) / 2;
        if (left) {
            if (nums[mid] >= target) {
                end = mid;
            } else {
                start = mid;
            }
        } else {
            if (nums[mid] <= target) {
                start = mid;
            } else {
                end = mid;
            }
        }
    }

    if (nums[start] == target) {
        return start;
    } else if (nums[end] == target) {
        return end;
    }
    return -1;
}

vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> result(2);
    int left = findPosition(nums, target, true);
    result[0] = left;
    int right = findPosition(nums, target, false);
    result[1] = right;

    return result;
}

int main()
{
    vector<int> nums = {5,7,7,8,8,10};
    int target = 10;

    PrintVector(searchRange(nums, target));
}
