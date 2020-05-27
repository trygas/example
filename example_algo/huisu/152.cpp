#include "general.h"

void Handle(vector<vector<int> > &res, int n, int index, int k,
            vector<int> &midRes)
{
    if(k == 0){
        res.push_back(midRes);
        return;
    }

    for(int i = index; i <= n - k + 1; ++i){
        midRes.push_back(i);
        Handle(res, n, i + 1, k - 1, midRes);
        midRes.pop_back();
    }
}

int main()
{
    int n = 2, k = 1;
    vector<vector<int > > res;
    vector<int> midRes;
    Handle(res, n, 1, k, midRes);
    PrintVectorVector(res);
}