#include "general.h"

int res = INT32_MAX;

vector<int> computeLeft(vector<int> &special, vector<int> &needs)
{
    vector<int> midRes;
    for(int j = 0; j < needs.size(); ++j){
        midRes.push_back(needs[j] - special[j]);
        if(midRes[j] < 0)
            return {};
    }
    return midRes;
}

void dfs(vector<int> &price, vector<vector<int> > &special,
         vector<int> needs, int ans)
{
    for(int i = 0; i < special.size(); ++i){
        int midAns = ans + special[i][special[i].size() - 1];
        int specialAns = ans + special[i][special[i].size() - 1];
        vector<int> midRes = computeLeft(special[i], needs);
        if(midRes.empty())
            continue;
        for(int j = 0; j < midRes.size(); ++j)
            specialAns += midRes[j] * price[j];

        res = min(res, specialAns);
        dfs(price, special, midRes, midAns);
    }
}

int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
{
    dfs(price, special, needs, 0);
    return res;
}


int main()
{
    vector<int> price = {2, 5};
    vector<vector<int> > special = {{3, 0, 5}, {1, 2, 10}};
    vector<int> needs = {3, 2};

    int midRes = 0;
    for(int i = 0; i < needs.size(); ++i){
        midRes += price[i] * needs[i];
    }
    res = std::min(res, midRes);

    shoppingOffers(price, special, needs);
    return res;
}