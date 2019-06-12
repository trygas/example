#include "general.h"

int solve(vector<int> &nums)
{
    const int n = nums.size();
    if (n < 2) {
        return 0;
    }
    vector<int> lMax(n), rMax(n), lMin(n), rMin(n);
    for (int i = 0, peek = INT32_MIN, cur = 0; i < n; i++) {
        cur += nums[i];
        peek = max(peek, cur);
        lMax[i] = peek;
        if (cur < 0) {
            cur = 0;
        }
    }
    for (int i = n - 1, peek = INT32_MIN, cur = 0; i > 0; i--) {
        cur += nums[i];
        peek = max(peek, cur);
        rMax[i - 1] = peek;
        if (cur < 0) {
            cur = 0;
        }
    }
    for (int i = 0, peek = INT32_MAX, cur = 0; i < n; i++) {
        cur += nums[i];
        peek = min(cur, peek);
        lMin[i] = peek;
        if (cur > 0) {
            cur = 0;
        }
    }
    for (int i = n - 1, peek = INT32_MAX, cur = 0; i > 0; i--) {
        cur += nums[i];
        peek = min(peek, cur);
        rMin[i - 1] = peek;
        if (cur > 0) {
            cur = 0;
        }
    }
    int result = INT32_MIN;
    for (int i = 0; i < n - 1; i++) {
        int temp = max(lMax[i] - rMin[i], rMax[i] - lMin[i]);
        result = max(result, temp);
    }
    return result;
}

int main()
{
    vector<int> data = {1, 2, -3, 1};
    cout << solve(data);
}