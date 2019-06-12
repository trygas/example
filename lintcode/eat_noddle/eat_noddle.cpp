#include <iostream>
#include <vector>

#include <algorithm>
#include "general.h"

using namespace std;



int helper(vector<vector<int> > &data)
{
    int max_noddle_number = 0;

    for (int i = 0; i < data.size(); ++i)
    {
        int noddle_number = 1;
        int last_noddle_number = 0;

        for (int j = i + 1; j < data.size(); ++j)
        {
            if(data[j][0] >= data[last_noddle_number][1])
            {
                noddle_number++;
                last_noddle_number = j;
            }
        }

        if (noddle_number > max_noddle_number)
        {
            max_noddle_number = noddle_number;
        }
    }

    return max_noddle_number;
}

int main()
{
    int number = 0;
    cin >> number;
    vector<vector<int > > data;

    for (int i = 0; i < number; ++i)
    {
        int first;
        int second;

        cin >> first >> second;
        data.push_back(vector<int>{first, second});
    }

    for (int i = 0; i < data.size(); ++i)
    {
        if(data[i][0] > data[i][1])
        {
            int number = data[i][0];
            data[i][0] = data[i][1];
            data[i][1] = number;
        }
    }

    sort(data.begin(), data.end(), [](vector<int> a, vector<int> b){return a[0] < b[0];});

    return helper(data);
}