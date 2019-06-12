#include <iostream>
#include <vector>

using namespace std;

bool CheckSquare(vector<vector<int> > &square, int i, int j, int z)
{
    for (int k = i - 1; k >= i - z; --k)
    {
        if (!square[k][j])
            return 0;
    }

    for (int l = j - 1; l >= j - z; --l)
    {
        if (!square[i][l])
            return 0;
    }

    return 1;
}

int helper(vector<vector<int> > &square)
{
    vector<vector<int> > result(square.size(), vector<int>(square[0].size(), 0));

    for (int i = 0; i < square.size(); ++i)
    {
        for (int j = 0; j < square[i].size(); ++j)
        {
            if(square[i][j] == 1)
                result[i][j] = 1;
        }
    }

    for (int i = 1; i < square.size(); ++i)
    {
        for (int j = 1; j < square[i].size(); ++j)
        {
            if (square[i][j] && result[i - 1][j - 1])
            {
                if(CheckSquare(square, i, j, result[i - 1][j - 1]))
                    result[i][j] = result[i - 1][j - 1] + 1;
            }
        }
    }

    int max_result = -1;

    for (int i = 0; i < square.size(); ++i)
    {
        for (int j = 0; j < square[i].size(); ++j)
        {
            if (result[i][j] > max_result)
                max_result = result[i][j];
        }
    }

    return max_result * max_result;
}

int main()
{
    vector<vector<int> > square = {{1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}};

    cout << helper(square);
}