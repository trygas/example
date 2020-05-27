#include "general.h"

int main()
{
    int N = 60, K = 55, W = 10;

    if(K == 0 || N >= (K + W))
        return 1.0;
    vector<double > nums(N + 1, 0);
    double res = 0.0;
    double sum = 0.0;
    for(int i = 1; i <= N; ++i){
        nums[i] = i <= W ? sum / W + 1.0 / W : sum / W;
        if(i < K)
            sum += nums[i];
        if(i > W)
            sum -= nums[i - W];
        if(i >= K)
            res += nums[i];
    }
    cout << res;
}