#include "general.h"

int solve(vector<int> &data)
{
    if (data.size() == 0 || data.size() == 1)
        return 0;

    int result = 0;

    for (int i = 1; i < data.size(); ++i)
    {
        if (data[i] > data[i - 1])
            result += data[i] - data[i - 1];
    }

    return result;
}

int main()
{
    vector<int> data = {2, 1, 2, 0, 1};
    cout << solve(data);
}