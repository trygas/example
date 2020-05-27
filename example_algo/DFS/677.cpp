#include "general.h"

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void dfs(vector<vector<bool> > &grid, int i, int j,
         vector<vector<bool> > &visited, int &size)
{
    int m = grid.size();
    int n = grid[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n)
        return;
    if (visited[i][j])
        return;
    visited[i][j] = true;
    if (grid[i][j])
        size++;
    else
        return;
    for(int k = 0; k < 4; ++k)
        dfs(grid, i + dx[k], j + dy[k], visited, size);
}

int Handle(vector<vector<bool> > &grid, vector<vector<bool> > &visited,
           int target)
{
    int m = grid.size();
    int n = grid[0].size();
    int sum = 0;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if (visited[i][j])
                continue;
            if (grid[i][j] ){
                int size = 0;
                dfs(grid, i, j, visited, size);
                if (size >= target)
                    sum++;
            }
        }
    }

    return sum;
}

int main()
{
    vector<vector<bool> > grid = {{1,1,0,0,0}, {0,1,0,0,1}, {0,0,0,1,1},
                                 {0,0,0,0,0}, {0,0,0,0,1}};
    int target = 2;

    vector<vector<bool> > visited(grid.size(), vector<bool>(grid[0].size(), false));
    cout << Handle(grid, visited, target);
}
