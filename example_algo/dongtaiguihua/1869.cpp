#include "general.h"

int countSquares(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int sum = 0;
    vector<vector<int> > res(m, vector<int>(n, 0));

    queue<pair<int, int> > q;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(matrix[i][j]){
                res[i][j] = 1;
                q.push({i, j});
                sum++;
            }
        }
    }

    while(!q.empty()){
        auto p = q.front();
        q.pop();
        if(p.first == 0 || p.second == 0)
            continue;

        pair<int, int> left = {p.first, p.second - 1},
                       up = {p.first - 1, p.second},
                       leftUp = {p.first - 1, p.second - 1};
        if(res[left.first][left.second] >= res[p.first][p.second] &&
           res[up.first][up.second] >= res[p.first][p.second] &&
           res[leftUp.first][leftUp.second] >= res[p.first][p.second]){
            sum++;
            res[p.first][p.second]++;
            q.push(p);
        }
    }

    return sum;
}

int main()
{
    vector<vector<int> > matrix = {{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}};
    cout << countSquares(matrix);
}
