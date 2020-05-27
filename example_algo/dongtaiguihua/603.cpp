#include "general.h"

int main()
{
    vector<int> nums = {1, 2, 3};

    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int> > res(n + 1, vector<int>());
    for(int i = 1; i <= n; ++i){
        res[i].emplace_back(nums[i - 1]);
    }
    for(int i = 2; i <= n; ++i){
        for(int j = 1; j <= i - 1; ++j){
            if (nums[i - 1] % nums[j - 1] == 0 && res[i].size() < res[j].size() + 1){
                res[i] = res[j];
                res[i].emplace_back(nums[i - 1]);
            }
        }
    }

    PrintVectorVector(res);
    int maxSize = -1;
    int maxIndex = -1;
    for(int i = 0; i < n; ++i){
        int k = res[i + 1].size();
        if (k > maxSize){
            maxSize = k;
            maxIndex = i + 1;
        }
    }
    PrintVector(res[maxIndex]);
}