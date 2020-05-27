#include "general.h"

bool ReachingPoints(vector<int> &start, vector<int> &target)
{
    while(true){
        if(start[0] > target[0] || start[1] > target[1])
            return false;
        if(start[0] == target[0] && start[1] == target[1])
            return true;
        if(target[0] > target[1])
            target[0] -= target[1];
        else
            target[1] -= target[0];
    }
}

int main()
{
    vector<int> start = {1, 2};
    vector<int> target = {99840,40832};

    return ReachingPoints(start, target);
}