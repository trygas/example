#include "general.h"

/*
 * 主要思路是先快排后,
 * 然后将有序数组分为两个部分, 首先从前半段的末尾取一个, 再从后半段取第一个
 * 然后以此类推.
 */
void handle(vector<int> &nums)
{
    int k = (nums.size() + 1) / 2;
    int j = nums.size();
    vector<int> temp = nums;
    sort(temp.begin(), temp.end());
    for(int i = 0; i < nums.size(); ++i)
        nums[i] = i & 1 ? temp[--j] : temp[--k];
}

int main()
{
    vector<int> num = {1, 5, 1, 1, 6, 4};
    handle(num);

    PrintVector(num);
}
