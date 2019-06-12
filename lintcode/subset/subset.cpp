#include <iostream>
#include <vector>

#include "general.h"

using namespace std;

bool subset_sort(vector<int> &subset, vector<vector<int> > &result, vector<int> &subset_result, int index)
{
    result.push_back(subset_result);

    for (int i = index; i < subset.size(); ++i)
    {
        if(i != index && subset{i} == subset{i - 1}) // 去掉这两行，就是计算无重复子集
            continue;

        subset_result.push_back(subset{i});
        subset_sort(subset, result, subset_result, i + 1);
        subset_result.pop_back();
    }
}

int main()
{
    vector<int> nums = {1, 2, 2};
    vector<vector<int> > result;
    vector<int> subset_result;
    int index = 0;

    subset_sort(nums, result, subset_result, index);

    PrintVectorVector(result);
}