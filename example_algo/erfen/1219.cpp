#include "general.h"

int findMinDis(int house, vector<int> &heaters)
{
    int left = 0, right = heaters.size() - 1;

    while(left + 1< right){
        int mid = left + (right - left) / 2;

        if(heaters[mid] == house)
            return 0;
        else if(heaters[mid] < house)
            left = mid;
        else
            right = mid;
    }

    return std::min(abs(house - heaters[left]), abs(house - heaters[right]));
}

int findRadius(vector<int> &houses, vector<int> &heaters)
{
    sort(heaters.begin(), heaters.end());

    int res = 0;
    for(int i = 0; i < houses.size(); ++i){
        res = std::max(findMinDis(houses[i], heaters), res);
    }

    return res;
}

int main()
{
    vector<int> houses = {1,2,3,4};
    vector<int> heaters = {1, 4};

    cout << findRadius(houses, heaters);
}