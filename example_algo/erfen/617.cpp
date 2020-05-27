#include "general.h"

double maxAverage(vector<int> &nums, int k)
{
    double l = INT32_MAX, r = INT32_MIN;
    int n = nums.size();
    for(int i = 0; i < n; ++i){
        l = std::min(l, (double)nums[i]);
        r = std::max(r, (double)nums[i]);
    }

    vector<double> sum(n + 1, 0);
    while(r - l > 1e-6){
        double mid = (l + r) / 2;

        for(int i = 0; i < n; ++i){
            sum[i + 1] = sum[i] + nums[i] - mid;
        }

        double premin = 0;
        double summax = INT32_MIN;
        for(int i = k; i <= n; ++i){
            premin = std::min(premin, )
        }
    }
}
