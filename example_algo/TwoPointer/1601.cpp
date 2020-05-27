#include "general.h"

int main()
{
    vector<int> people = {3, 5, 3, 4};
    int limit = 5;

    int res = 0;
    sort(people.begin(), people.end());
    int right = people.size() - 1;
    int left = 0;
    while(left <= right){
        if(left == right){
            res++;
            break;
        }
        if(people[right] >= limit){
            res++;
            right--;
            continue;
        }
        else{
            if(people[left] + people[right] <= limit){
                left++;
                right--;
                res++;
            }
            else {
                right--;
                res++;
            }
            continue;
        }
    }

    cout << res;
}