#include "general.h"

void Handle(vector<int> &candidates, int target, int index,
            vector<vector<int> > &res, vector<int> &midRes)
{
    if(0 == target){
        res.push_back(midRes);
        return;
    }

    for(int i = index; i < candidates.size(); ++i){
        if(candidates[i] > target)
            break;
        if(i != index && candidates[i] == candidates[i - 1])
            continue;
        midRes.push_back(candidates[i]);
        Handle(candidates, target - candidates[i], i, res, midRes);
        midRes.pop_back();
    }
}

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int> > res;
    vector<int> midRes;

    sort(candidates.begin(), candidates.end());
    Handle(candidates, target, 0, res, midRes);
    PrintVectorVector(res);
}