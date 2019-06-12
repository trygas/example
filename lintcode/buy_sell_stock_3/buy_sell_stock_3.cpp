#include "general.h"

int solve(vector<int> &data)
{
    if (data.size() == 0 || data.size() == 1)
        return 0;

    vector<int> left(data.size(), 0);
    vector<int> right(data.size(), 0);

    int min_number = data[0];
    for (int i = 1; i < data.size(); ++i)
    {
        if (min_number < data[i])
        {
            if (left[i - 1] < (data[i] - min_number))
                left[i] = data[i] - min_number;
            else
                left[i] = left[i - 1];
        }
        else
        {
            min_number = data[i];
            left[i] = left[i - 1];
        }
    }

    int max_number = data[data.size() - 1];
    for (int j = data.size() - 2; j >= 0; --j)
    {
        if (max_number > data[j])
        {
            if (right[j + 1] < max_number - data[j])
                right[j] = max_number - data[j];
            else
                right[j] = right[j + 1];
        }
        else
        {
            max_number = data[j];
            right[j] = right[j + 1];
        }
    }

    int result = 0;
    for (int k = 0; k < data.size(); ++k)
    {
        if (left[k] + right[k + 1] > result)
            result = left[k] + right[k + 1];
    }

    return result;
}

int main()
{
    vector<int> data = {1, 2};

    cout << solve(data);
}