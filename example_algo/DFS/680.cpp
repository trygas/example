#include "general.h"

void dfs(string &s, vector<vector<string> > &res, vector<string> &midRes,
         int index)
{
    if (index >= s.size()){
        res.emplace_back(midRes);
        return;
    }

    vector<string> anoMidRes = midRes;
    anoMidRes.emplace_back(s.substr(index, 1));
    dfs(s, res, anoMidRes, index + 1);
    if(index + 2 > s.size())
        return;
    midRes.emplace_back(s.substr(index, 2));
    dfs(s, res, midRes, index + 2);
    return;
}

int main()
{
    string s = "12345";

    vector<vector<string> > res;
    vector<string> midRes;
    dfs(s, res, midRes, 0);
    PrintVectorVector(res);
}
