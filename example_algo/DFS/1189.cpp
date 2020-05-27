#include "general.h"

int m, n;
vector<vector<int>> vc;  // Record how many mines are around each grid


inline
int init(vector<vector<int>>& vc, const vector<vector<char>>& board) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ('M' == board[i][j]) {
                vc[i][j] = -1;   // -1 means that it is a mine
                for (int k = 0; k < 8; k++) {
                    int tx = i + dx[k];
                    int ty = j + dy[k];
                    if (0 <= tx && tx < m && 0 <= ty && ty < n) {
                        if ('M' != board[tx][ty]) {
                            vc[tx][ty]++;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {

    m = board.size();
    if (!m) return board;
    n = board[0].size();
    if (!n) return board;

    vc = vector<vector<int>>(m, vector<int>(n, 0));
    init(vc, board);

    int x = click[0], y = click[1];
    if ('M' == board[x][y]) {  // game over
        board[x][y] = 'X';
        return board;
    }

    if ('E' == board[x][y]) {  // blank square
        if (vc[x][y]) {   // There are mines around, you can modify the numbers.
            board[x][y] = char(vc[x][y] + '0');
            return board;
        } else {    // There are no mines around, deep search
            dfs(board, x, y);
        }
    }

    return board;
}


int dfs(vector<vector<char>>& board, int x, int y) {
    board[x][y] = 'B';
    for (int k = 0; k < 8; k++) {
        int tx = x + dx[k];
        int ty = y + dy[k];
        if (0 <= tx && tx < m && 0 <= ty && ty < n && 'B' != board[tx][ty]) {
            if (vc[tx][ty]) {
                board[tx][ty] = char(vc[tx][ty] + '0');
            } else if ('E' == board[tx][ty]) {
                board[tx][ty] = 'B';
                dfs(board, tx, ty);
            }
        }
    }
    return 0;
}

int main()
{
    vector<vector<char> > board = {{'E', 'E', 'E', 'E', 'E'},
                                   {'E', 'E', 'M', 'E', 'E'},
                                   {'E', 'E', 'E', 'E', 'E'},
                                   {'E', 'E', 'E', 'E', 'E'}};
    vector<int> click = {3, 0};
    updateBoard(board, click);
    PrintVectorVector(board);
}