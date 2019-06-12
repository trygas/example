#include "general.h"

vector<int> solve(vector<int> &data, int target)
{
    if (data.empty())
        return vector<int>(2, -1);

    vector<int> result;
    int l = 0, r = data.size() - 1;
    int mid;
    int ansl = -1, ansr = -1;

    while (l <= r)
    {
        mid = (l + r) / 2;

        if (data[mid] > target)
        {
            r = mid - 1;
        }
        else if(data[mid] < target)
        {
            l = mid + 1;
        }
        else if (data[mid] == target)
        {
            r = mid - 1;
            ansl = mid;
        }
    }

    if (ansl != -1)
        result.push_back(ansl);
    else
        return vector<int>(2, -1);

    l = 0;
    r = data.size() - 1;

    while (l <= r)
    {
        mid = (l + r) / 2;

        if (data[mid] < target)
            l = mid + 1;
        else if (data[mid] > target)
            r = mid - 1;
        else
        {
            ansr = mid;
            l = mid + 1;
        }
    }

    result.push_back(ansr);

    return result;
}

int main()
{
    vector<int> data = {5, 7, 7, 8, 8, 10};
    PrintVector(solve(data, 8));
}