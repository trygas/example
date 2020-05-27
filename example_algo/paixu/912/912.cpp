#include "general.h"

int dis(vector<int> &x)
{
    sort(x.begin(), x.end());
    int left = 0, right = x.size() - 1;
    int res = 0;
    while (left < right){
        res += x[right--] - x[left++];
    }
    return res;
}

int handle(vector<vector<int > > &nums)
{
    vector<int> x, y;
    for(int i = 0; i < nums.size(); ++i){
        for(int j = 0; j < nums[i].size(); ++j){
            if (nums[i][j]){
                x.emplace_back(i);
                y.emplace_back(j);
            }
        }
    }

    return dis(x) + dis(y);
}

int main()
{
    vector<vector<int > > nums = {{1,1,0,0,1}, {1,0,1,0,0}, {0,0,1,0,1}};
    cout << handle(nums);
}
