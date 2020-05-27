#include "general.h"

/*
 * res[i][j]表示从星球0出发到达星球i后拥有j个金币的方案数
 */
int main()
{
    int n = 1, m = 1, limit = 1;
    vector<int> cost = {0, 1};

    vector<vector<int > > res(n + 1, vector<int>(m + 1, 0));
    res[0][m] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= m; ++j){
            // 这个思路就是遍历之前的所有的节点
            for(int t = std::max(0, i - limit); t <= i - 1; ++t){
                if(j + cost[i] <= m){
                    res[i][j] += res[t][j + cost[i]];
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= m; ++i){
        ans += res[n][i];
    }

    cout << ans;
}
