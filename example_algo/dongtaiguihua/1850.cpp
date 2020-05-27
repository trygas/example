#include "general.h"

/*
 * 主要思路是四遍dp计算, Alice和Bob从左到右的最大值和从右到左的最大值
 * 然后遍历每一个点, 比较A从这个点左边, B在该点右边的最大值和A在这个点右边, B在这个点左边的最大值
 */
vector<int> get_dp(vector<int> &nums, int limit)
{
    int arr_sum = 0, index = limit;
    vector<int> result(nums.size(), -1);

    for(int i = 0; i < limit; ++i)
        arr_sum += nums[i];
    while(index < nums.size()){
        arr_sum = arr_sum + nums[index] - nums[index - limit];
        result[index] = std::max(result[index - 1], arr_sum);
        index++;
    }

    return result;
}

int PickApples(vector<int> &A, int K, int L)
{
    int n = A.size();
    if(K + L > n)
        return -1;

    vector<int> left_A = get_dp(A, K);
    vector<int> left_B = get_dp(A, L);

    reverse(A.begin(), A.end());
    vector<int> right_A = get_dp(A, K);
    vector<int> right_B = get_dp(A, L);

    reverse(right_A.begin(), right_A.end());
    reverse(right_B.begin(), right_B.end());

    int ans = -1, temp_maximum = -1;
    for(int i = 0; i < n - 1; ++i){
        temp_maximum = -1;
        if(left_A[i] != -1 && right_B[i + 1] != -1)
            temp_maximum = std::max(temp_maximum, left_A[i] + right_B[i + 1]);
        if(left_B[i] != -1 && right_A[i + 1] != -1)
            temp_maximum = std::max(temp_maximum, left_B[i] + right_A[i + 1]);

        ans = std::max(ans, temp_maximum);
    }

    return ans;
}