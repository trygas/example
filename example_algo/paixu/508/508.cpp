#include "general.h"

/*
 * 主要思路是分奇数和偶数
 * 当i为奇数时, 只要nums[i] > nums[i + 1]
 * 或i为偶数时, nums[i] < nums[i + 1]
 * 就要交换nums[i]和nums[i + 1]
 */
void handle(vector<int> &nums)
{
    if (nums.size() == 0)
        return;
    for (int i = 0; i < nums.size() - 1; ++i)
    {
        if (i % 2 == 0 && nums[i] > nums[i + 1] ||
            i % 2 == 1 && nums[i] < nums[i + 1])
            swap(nums[i], nums[i + 1]);
    }
}

int main()
{
    vector<int> nums = {3, 5, 2, 1, 6, 4};
    handle(nums);
    PrintVector(nums);
}