#include "general.h"

int main()
{
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;

    int res = 0;
    for(int i = 0; i < nums.size(); ++i){
        int time = 1;
        for(int j = i; j < nums.size(); ++j){
            time = time * nums[j];
            if(time < k)
                res++;
            else
                break;
        }
    }

    cout << res;
}