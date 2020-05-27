#include "general.h"

int Sum(vector<int> &vec)
{
    int sum = 0;
    for(int &num: vec)
        sum += num;
    return sum;
}

void Handle(vector<int> &nums, int target, int index, vector<int> &midRes,
            vector<vector<int> > &res)
{
    map<int, int> visited;
    for(int i = index; i < nums.size(); ++i){
        if (visited[nums[i]] != 0)
            continue;
        visited[nums[i]]++;

        midRes.emplace_back(nums[i]);
        int sum = Sum(midRes);
        if (sum == target)
            res.emplace_back(midRes);
        else if (sum < target)
            Handle(nums, target, i + 1, midRes, res);
        midRes.pop_back();
    }
}

int main()
{
    vector<int> num = {7,1,2,5,1,6,10};
    int target = 8;

    sort(num.begin(), num.end());
    vector<vector<int> > res;
    vector<int> midRes;
    Handle(num, target, 0, midRes, res);
    PrintVectorVector(res);
}
