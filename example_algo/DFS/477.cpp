#include "general.h"

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(vector<vector<char> > &board, vector<vector<bool> > &visited,
         vector<vector<bool> > &right, int x, int y)
{
    int m = board.size();
    int n = board[0].size();

    if (x < 0 || x >= n || y < 0 || y >= m)
        return;

    if(visited[x][y])
        return;
    visited[x][y] = true;
    if (board[x][y] == 'X')
        return;
    right[x][y] = true;

    for(int i = 0; i < 4; ++i){
        dfs(board, visited, right, x + dx[i], y + dy[i]);
    }
}

void Handle(vector<vector<char> > &board)
{
    int m = board.size();
    int n = board[0].size();
    vector<vector<char> > res(m, vector<char>(n));
    vector<vector<bool> > right(m, vector<bool>(n, false));
    vector<vector<bool> > visited(m, vector<bool>(n, false));

    for(int i = 0; i < m; ++i){
        dfs(board, visited, right, i, 0);
        dfs(board, visited, right, i, n - 1);
    }
    for(int i = 0; i < n; ++i){
        dfs(board, visited, right, 0, i);
        dfs(board, visited, right, m - 1, i);
    }

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(!right[i][j] || board[i][j] == 'X')
                res[i][j] = 'X';
            else
                res[i][j] = 'O';
        }
    }

    PrintVectorVector(res);
}

int main()
{
    vector<vector<char> > board = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'},
                                   {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};

    Handle(board);
}
