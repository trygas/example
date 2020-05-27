#include "general.h"

int Sum(vector<int> &vec)
{
    int sum = 0;
    for(int i: vec){
        sum += i;
    }
    return sum;
}

void Handle(vector<int> &nums, vector<vector<int> > &res, int k, int target,
            vector<int> midRes, int index)
{
    if(midRes.size() > k)
        return;

    int sum = Sum(midRes);
    if(sum > target)
        return;

    if (sum == target && midRes.size() == k){
        res.emplace_back(midRes);
        return;
    }

    for(int i = index; i < nums.size(); ++i){
        midRes.emplace_back(nums[i]);
        Handle(nums, res, k, target, midRes, i + 1);
        midRes.pop_back();
    }
}

int main()
{
    vector<int> A = {1,2,3,4};
    int k = 2;
    int target = 5;

    vector<vector<int> > res;
    vector<int> midRes;
    Handle(A, res, k, target, midRes, 0);
    PrintVectorVector(res);
}
