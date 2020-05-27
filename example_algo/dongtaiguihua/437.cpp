#include "general.h"

int main()
{
    vector<int> pages = {3, 2, 4};
    int k = 2;

    int n = pages.size();
    vector<vector<int> > res(k+1, vector<int>(n+1, INT32_MAX));
    vector<int> sum;
    int subsum = 0;
    for(int i = 0; i < pages.size(); ++i){
        subsum+=pages[i];
        sum.emplace_back(subsum);
    }
    for(int i = 0; i <= k; ++i){
        res[i][0] = 0;
    }
    for(int i = 1; i <= k; ++i){
        for(int j = 1; j <= n; ++j){
            int sum = 0;
            for(int m = j; m >= 0; --m){
                res[i][j] = std::min(res[i][j], std::max(res[i-1][m], sum));
                if (m > 0)
                    sum += pages[m - 1];
            }
        }
    }

    PrintVectorVector(res);
}
