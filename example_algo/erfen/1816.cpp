#include "general.h"

int smallestDivisor(vector<int> &nums, int threshold)
{
    int maxNum;
    FindMaxNumber(nums, maxNum);
    int res = INT32_MAX;

    int left = 1, right = maxNum;
    while(left < right){
        int sum = 0;
        int mid = (left + right) / 2;

        for(int i = 0; i < nums.size(); ++i){
            int ans = nums[i] / mid;
            int other = nums[i] % mid;
            if(other != 0)
                ans++;

            sum += ans;
        }

        if(sum <= threshold){
            right = mid;
            res = std::min(res, mid);
        }
        else
            left = mid + 1;
    }

    return left;
}

int main()
{
    vector<int> nums = {2,3,5,7,11};
    int threshold = 11;
    cout << smallestDivisor(nums, threshold);
}
