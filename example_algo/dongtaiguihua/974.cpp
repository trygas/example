#include "general.h"

vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    queue<pair<int, int> > q;
    vector<vector<int> > res(m, vector<int>(n, -1));
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(matrix[i][j] == 0){
                q.push(make_pair(i, j));
                res[i][j] = 0;
            }
        }
    }

    while(!q.empty()){
        auto p = q.front();
        q.pop();

        for(int i = 0; i < 4; ++i){
            int newx = p.first + dx[i];
            int newy = p.second + dy[i];

            if(newx >= 0 && newx < m && newy >= 0 && newy < n &&
               res[newx][newy] == -1){
                res[newx][newy] = res[p.first][p.second] + 1;
                q.push(make_pair(newx, newy));
            }
        }
    }

    return res;
}

int main()
{
    vector<vector<int> > matrix = {{0,1,0,1,1}, {1,1,0,0,1}, {0,0,0,1,0},
                                   {1,0,1,1,1}, {1,0,0,0,1}};

    PrintVectorVector(updateMatrix(matrix));
}
