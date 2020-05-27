#include "general.h"

int main()
{
    vector<int> nums = {0, 1, 1, 1, 1, 1, 1, 0};

    int res = 0;
    int left = -1;
    int begin = 0;
    for(int i = 0; i < nums.size(); ++i){
        if(!nums[i]){
            if(left == -1)
                left = i;
            else{
                res = std::max(res, i - begin);
                begin = left + 1;
                left = i;
            }
        }
    }

    cout << res;
}