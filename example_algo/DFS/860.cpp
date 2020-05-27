#include "general.h"

int numberofDistinctIslands(vector<vector<int>> &grid)
{
    set<string> res;
    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int, int> > q;
    vector<vector<int > > visited(m, vector<int>(n, false));
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(grid[i][j] == 1 && visited[i][j] == false)
                q.push(make_pair(i, j));

            string midRes;
            auto first = make_pair(i, j);
            while(!q.empty()){
                auto p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                visited[x][y] = true;
                midRes += to_string(x - first.first) + "," +
                          to_string(y - first.second) + " ";

                for(int k = 0; k < 4; ++k){
                    int newx = x + dx[k];
                    int newy = y + dy[k];
                    if(newx < 0 || newx >= m ||
                       newy < 0 || newy >= n ||
                       visited[newx][newy] || !grid[newx][newy])
                        continue;
                    q.push(make_pair(newx, newy));
                }
            }
            if(!midRes.empty())
                res.insert(midRes);
        }
    }

    return res.size();
}

int main()
{
    vector<vector<int> > grid = {{1,1,0,0,1}, {1,0,0,0,0}, {1,1,0,0,1}, {0,1,0,1,1}};

    return numberofDistinctIslands(grid);
}
