#include "general.h"

int solve(vector<int>& data)
{
    vector<int> left(data.size());
    vector<int> right(data.size());

    int maximum = 0;
    int sum = 0;

    for (int i = 0; i < data.size(); ++i)
    {
        sum += data[i];
        if (sum > maximum)
            maximum = sum;

        if (sum < 0)
            sum = 0;

        left[i] = maximum;
    }

    sum = 0;
    maximum = 0;

    for (int j = data.size() - 1; j >= 0; --j)
    {
        sum += data[j];
        if (sum > maximum)
            maximum = sum;

        if (sum < 0)
            sum = 0;

        right[j] = maximum;
    }

    int result = 0;

    PrintVector(left);
    PrintVector(right);

    for (int k = 0; k < data.size() - 1; ++k)
    {
        result = max(result, left[k] + right[k + 1]);
    }

    return result;
}

int main()
{
    vector<int> data = {1, 3, -1, 2, -1, 2};

    cout << solve(data);
}