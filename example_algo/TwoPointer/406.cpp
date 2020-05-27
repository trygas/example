#include "general.h"

int main()
{
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int s = 7;

    int begin = -1;
    int minLen = nums.size();
    int sum = 0;
    for(int i = 0, start = 0; i < nums.size(); ++i){
        sum += nums[i];
        if(sum >= s){
            while(start < i && sum - nums[start] >= s){
                sum -= nums[start];
                start++;
            }

            if(i - start < minLen){
                minLen = i - start;
                begin = start;
            }

            sum -= nums[start];
            start++;
        }
    }

    cout << begin << " " << minLen;
}