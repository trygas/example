#include "general.h"

void dfs(int stx, int sty, vector<vector<int>> & dis,
         vector<vector<int>> & matrix, int cursum, int edx, int edy)
{
    dis[stx][sty] = cursum;
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i = 0; i < 4; ++i){
        int nx = stx + dx[i];
        int ny = sty + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m ||
           dis[nx][ny] < cursum + matrix[nx][ny])
            continue;
        dfs(nx, ny, dis, matrix, cursum + matrix[nx][ny], 0, m - 1);
    }
}

int minPathSumII(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int> > dp(m, vector<int>(n, INT32_MAX));
    dp[m - 1][0] = matrix[m - 1][0];
    dfs(m - 1, 0, dp, matrix, matrix[m - 1][0], 0, n - 1);
    return dp[0][n - 1];
}
