#include "general.h"

bool canCross(vector<int> &stones)
{
    map<int, set<int> > res;
    res[0].insert(0);

    for(int i = 1; i < stones.size(); ++i){
        for(int j = i - 1; j >= 0; --j){
            int dis = stones[i] - stones[j];
            if(res[stones[j]].count(dis - 1) || res[stones[j]].count(dis) ||
               res[stones[j]].count(dis + 1))
                res[stones[i]].insert(dis);
        }

        if(res[stones[i]].empty())
            return false;
    }

    return true;
}

int main()
{
    vector<int> stone = {0,1,3,5,6,8,12,17};

    return canCross(stone);
}