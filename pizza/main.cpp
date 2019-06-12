#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int number_orders = 6;
    int size = 3;
    vector<int> orders = {-11, -2, 19, 37, 64, -18};
    vector<int> result;
    vector<int> index;

    for(int i = 0; i < size; ++i)
    {
        if (orders[i] < 0)
        {
            index.push_back(i);
        }
    }

    for(int vector_index = size; vector_index < orders.size() + 1; ++vector_index)
    {
        if (!index.empty())
        {
            result.push_back(orders[vector_index + index[0] - size]);
        }
        else
        {
            result.push_back(0);
        }

        if (orders[vector_index] < 0)
        {
            index.push_back(size);
        }

        for (int i = 0; i < index.size(); ++i)
        {
            index[i] -= 1;
        }

        if (index[0] < 0)
        {
            index.erase(index.begin());
        }
    }

    for(int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}