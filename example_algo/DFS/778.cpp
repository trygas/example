#include "general.h"

/*
 * 这道题的重点就是创建一个数组记录走过的地方
 */

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void dfs(vector<vector<int> > &matrix, vector<vector<bool> > &visited,
         int height, int x, int y)
{
    int n = matrix.size();
    int m = matrix[0].size();
    if (x < 0 || x >= n || y < 0 || y >= m || matrix[x][y] < height || visited[x][y])
        return;
    visited[x][y] = true;
    for(int i = 0; i < 4; ++i)
        dfs(matrix, visited, matrix[x][y], x + dx[i], y + dy[i]);
}

void Handle(vector<vector<int> > &matrix, vector<vector<int> > &res)
{
    int n = matrix.size();
    if (n == 0)
        return;
    int m = matrix[0].size();

    vector<vector<bool> > Pacific(n, vector<bool>(m, false));
    vector<vector<bool> > Atlantic(n, vector<bool>(m, false));
    for(int i = 0; i < n; ++i){
        dfs(matrix, Pacific, INT32_MIN, i, 0);
        dfs(matrix, Atlantic, INT32_MIN, i, m - 1);
    }
    for(int i = 0; i < m; ++i){
        dfs(matrix, Pacific, INT32_MIN, 0, i);
        dfs(matrix, Atlantic, INT32_MIN, n - 1, i);
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if (Pacific[i][j] && Atlantic[i][j]){
                vector<int> temp = {i, j};
                res.emplace_back(temp);
            }
        }
    }
}

int main()
{
    std::vector<vector<int> > matrix ={{1,2,2,3,5}, {3,2,3,4,4}, {2,4,5,3,1},
                                       {6,7,1,4,5}, {5,1,1,2,4}};
    vector<vector<int> > res;
    Handle(matrix, res);
    PrintVectorVector(res);
}
