#include "general.h"

int modernLudo(int length, vector<vector<int>> &connections)
{
    map<int, set<int> > m;
    for(int i = 0; i < connections.size(); ++i){
        m[connections[i][1]].insert(connections[i][0]);
    }

    vector<int> dp(length + 1, INT32_MAX);
    dp[0] = 0;
    dp[1] = 0;
    for(int i = 2; i <= length; ++i){
        for(int j = i - 1; j >= 1 && j >= i - 6; --j){
            dp[i] = std::min(dp[j] + 1, dp[i]);
        }
        for(int k: m[i])
            dp[i] = std::min(dp[k], dp[i]);
    }

    return dp[length];
}

int main()
{
    int length = 15;
    vector<vector<int> > connections = {{7, 9}, {8, 14}};
    cout << modernLudo(length, connections);
}