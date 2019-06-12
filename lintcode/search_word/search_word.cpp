#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool search(vector<string> &board, string &word, int i, int j, int z, vector<vector<bool> > path)
{
    if (z == word.size())
        return true;

    if (i - 1 >= 0 && !path[i - 1][j])
    {
        if(board[i - 1][j] == word[z])
        {
            path[i - 1][j] = true;
            if(search(board, word, i - 1, j, z + 1, path))
                return 1;
        }
    }
    if(i + 1 < board.size() && !path[i + 1][j])
    {
        if (board[i + 1][j] == word[z])
        {
            path[i + 1][j] = true;
            if(search(board, word, i + 1, j, z + 1, path))
                return 1;
        }
    }
    if (j - 1 >= 0 && !path[i][j - 1])
    {
        if(board[i][j - 1] == word[z])
        {
            path[i][j - 1] = true;
            if(search(board, word, i, j - 1, z + 1, path))
                return 1;
        }
    }
    if(j + 1 < board[i].size() && !path[i][j + 1])
    {
        if (board[i][j + 1] == word[z])
        {
            path[i][j + 1] = true;
            if(search(board, word, i, j + 1, z + 1, path))
                return 1;
        }
    }

    path[i][j] = false;
    return 0;
}

bool helper(vector<string> &board, string &word)
{
    vector<vector<bool> > path(board.size(), vector<bool>(board[0].size(), false));

    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[i].size(); ++j)
        {
            if (board[i][j] == word[0])
            {
                path[i][j] = true;
                int res = search(board, word, i, j, 1, path);

                if (res)
                    return 1;
            }
        }
    }

    return 0;
}

int main()
{
    vector<string > board = {"ABCE", "SFCS", "ADEE"};
    string word = "ABCCED";

    cout << helper(board, word);
}