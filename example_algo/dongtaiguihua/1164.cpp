#include "general.h"

int main()
{
    vector<int> nums = {3,3,3};

    int res = 0;
    int flag = nums[1] - nums[0];
    if (flag != 0)
        res = 2;
    for(int i = 2; i < nums.size(); ++i){
        int min = nums[i] - nums[i - 1];
        if(flag * min < 0)
        {
            if (res)
                res++;
            else if(res == 0)
                res += 3;
        }
        if(min != 0)
            flag = min;
    }

    cout << res;
}
