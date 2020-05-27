#include "general.h"

int main()
{
    vector<vector<int > > nums = {{1,2,3,4},{3,5,6,7},{9,10,1,2},{4,4,5,5}};
    vector<vector<int > > res(nums.size() + 1, vector<int>(nums[0].size() + 1, 0));

    for(int i = 1; i <= nums.size(); ++i){
        for(int j = nums[0].size(); j >= 0; --j){
            if (i != 1 && j != nums[0].size()){
                res[i][j] = std::max(res[i-1][j], res[i][j+1]) + nums[i-1][j-1];
            }
            else if(i == 1 && j == nums[0].size()){
                res[i][j] = nums[i-1][j-1];
            }
            else if(i == 1){
                res[i][j] = res[i][j+1] + nums[i-1][j-1];
            }
            else if (j == nums[0].size()){
                res[i][j] = res[i-1][j] + nums[i-1][j-1];
            }
        }
    }

    PrintVectorVector(res);
}

