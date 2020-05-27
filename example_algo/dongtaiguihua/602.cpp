#include "general.h"

/*
 * 思路是首先对一个维度进行排序, 然后在另一个维度上寻找最长上升子序列.
 */
bool cmp(const pair<int,int>&x, const pair<int, int>&y) {
    return x.first != y.first ? x.first < y.first : x.second > y.second;
}

int maxEnvelopes(vector<pair<int, int>>& envelopes)
{
    int n = envelopes.size();
    if (n == 0) {
        return 0;
    }

    sort(envelopes.begin(), envelopes.end(), cmp);
    vector<int> dp(n), height(n+1, INT32_MAX);
    for (int i = 0; i < n; i++) {
        int k = lower_bound(height.begin(), height.end(), envelopes[i].second) - height.begin() ;
        dp[i] = k;
        height[k] = envelopes[i].second;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }
    return ans + 1;
}


int main()
{
    vector<pair<int, int> > envelopes = {{1, 2}, {1, 1}, {1, 3}};
    return maxEnvelopes(envelopes);
}