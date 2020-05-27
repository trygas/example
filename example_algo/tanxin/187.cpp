#include "general.h"

/*
 * 思路就是如果一个数组的总累加和非负, 那么一定存在一个起始位置,
 * 使得从这个位置绕数组一圈, 累加和一直都是非负的.
 */
int main()
{
    vector<int> gas = {1, 1, 3, 1};
    vector<int> cost = {2, 2, 1, 1};

    vector<int> minus;
    int sum = 0;
    for(int i = 0; i < gas.size(); ++i){
        minus.push_back(gas[i] - cost[i]);
        sum += minus.back();
    }

    if(sum < 0)
        return -1;

    sum = 0;
    int res = 0;
    for(int i = 0; i < minus.size(); ++i){
        sum += minus[i];
        if(sum < 0){
            sum = 0;
            res = i + 1;
        }
    }

    cout << res;
}