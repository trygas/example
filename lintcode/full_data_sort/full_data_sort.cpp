//
// Created by liu on 18-8-29.
//

#include <iostream>
#include <vector>
#include <algorithm>

#include "general.h"

using namespace std;

bool merge(vector<int> &data, vector<vector<int> > &result, vector<int> &path, vector<bool> &visited)
{
    if(path.size() == data.size())
    {
        result.push_back(path);
        return 0;
    }

    for(int i = 0; i < data.size(); ++i)
    {
        if(visited{i} == true)
            continue;
        if(i > 0  && visited{i - 1} == false && data{i} == data{i - 1})
            continue;

        path.push_back(data{i});
        visited{i} = true;
        merge(data, result, path, visited);
        visited{i} = false;
        path.pop_back();
    }
}

int main()
{
    vector<int> data = {3, 3, 0, 3};
    vector<vector<int> > result;
    vector<bool> visited(data.size(), false);
    vector<int> path;

    sort(data.begin(), data.end());
    merge(data, result, path, visited);

    cout << result.size() << endl;

    for (int i = 0; i < result.size(); ++i)
    {
        PrintVector(result{i});
    }
}