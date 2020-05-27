#include "general.h"

int main()
{
    vector<int> A = {1, 2};
    int K = 1;

    int n = A.size();
    vector<int> sum(n + 1, 0);
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        ans += A[i - 1];
        sum[i] = ans;
    }

    vector<vector<double > > res(n + 1, vector<double>(K + 1, 0));
    for(int i = 1; i <= n; ++i){
        res[i][1] = (double)sum[i] / i;
    }
    for(int i = 2; i <= n; ++i){
        for(int j = 2; j <= K; ++j){
            for(int k = 1; k < i; ++k){
                res[i][j] =
                    std::max(res[i][j], res[k][j - 1] + (double)(sum[i] - sum[k]) / (double)(i - k));
            }
        }
    }

    PrintVectorVector(res);
}
