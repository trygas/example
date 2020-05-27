#include "general.h"

void Handle(vector<int> &nums, const int &index, vector<int> &subset, vector<vector<int> > &res)
{
    // 这个数组是为了确保具有相同的数值的vector不被计入结果
    vector<bool> visited(201, false);
    for(int i = index; i < nums.size(); ++i){
        if (subset.size() > 0 && subset.back() > nums[i])
            continue;
        if (visited[nums[i] + 100])
            continue;
        subset.emplace_back(nums[i]);
        visited[nums[i] + 100] = true;
        if (subset.size() >= 2){
            vector<int> solution = subset;
            res.emplace_back(solution);
        }
        // 增加更多的位数
        Handle(nums, i + 1, subset, res);
        // 增加更多的相同位数的数组
        subset.pop_back();
    }

    return;
}

int main()
{
    vector<int> nums = {4, 6, 7, 7};

    vector<vector<int> > res;
    vector<int> midRes;
    Handle(nums, 0, midRes, res);
    PrintVectorVector(res);
}
