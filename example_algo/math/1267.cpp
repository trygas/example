#include "general.h"

void dfs(vector<int> &res, int index, int target)
{
    if(index > target)
        return;
    res.push_back(index);
    for(int i = 0; i < 10; ++i){
        dfs(res, index * 10 + i, target);
    }
}

vector<int> lexicalOrder(int n)
{
    vector<int> res;

    for(int i = 1; i < 10; ++i)
        dfs(res, i, n);

    return res;
}

int main()
{
    int n = 223;
    PrintVector(lexicalOrder(n));
}
