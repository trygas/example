#include "general.h"

int solve(vector<int> &data)
{
    if (data.size() == 0 || data.size() == 1)
        return 0;

    vector<int> result(data.size(), 0);
    int min_data = data[0];

    for (int i = 1; i < data.size(); ++i)
    {
        int profit = data[i] - min_data;

        if (profit < 0)
            result[i] = 0;
        else
            result[i] = profit;
        if (min_data > data[i])
            min_data = data[i];
    }

    int return_number = FindMaxNumber(result);

    return return_number;
}

int main()
{
    vector<int> data = {3, 2, 3, 1, 2};
    cout << solve(data);
}