#include "general.h"

int solve(vector<int>& A, int k, int target)
{
    if (A.empty() || k == 0 || target == 0)
        return 0;

    vector<vector<vector<int> > > result(A.size() + 1, vector<vector<int> >(k + 1, vector<int>(target + 1, 0)));

    for (int i = 0; i <= A.size(); ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            for (int l = 0; l <= target; ++l)
            {
                if (j == 0 && l == 0)
                {
                    result[i][j][l] = 1;
                }
                else if (!(i == 0 || j == 0 || l == 0))
                {
                    result[i][j][l] = result[i - 1][j][l];
                    if (l >= A[i - 1])
                    {
                        result[i][j][l] += result[i - 1][j - 1][l - A[i - 1]];
                    }
                }
            }
        }
    }

    return result[A.size()][k][target];
}

int main()
{
    vector<int> data = {1, 2, 3, 4};
    int k = 2;
    int target = 5;

    cout << solve(data, k, target);
}