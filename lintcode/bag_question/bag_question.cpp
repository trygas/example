#include "general.h"

int solve(int m, vector<int> &data)
{
    if (m == 0 || data.empty())
        return 0;

    vector<int> result(m + 1, 0);

    for (int i = 0; i < data.size(); ++i)
    {
        for (int j = m; j >= data[i]; --j)
        {
            result[j] = max(result[j], result[j - data[i]] + data[i]);
        }
    }

    return result[m];
}

int main()
{
    vector<int> data = {2, 3, 5, 7};
    cout << solve(11, data);
}