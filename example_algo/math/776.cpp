#include "general.h"

void dfs(vector<string> &res, int index, string &midRes)
{
    if(midRes.size() % 2 == 0 && index >= midRes.size() / 2){
        res.push_back(midRes);
        return;
    }
    else if(midRes.size() % 2 != 0 && index == midRes.size() / 2){
        midRes[index] = '0';
        res.push_back(midRes);
        midRes[index] = '1';
        res.push_back(midRes);
        midRes[index] = '8';
        res.push_back(midRes);
    }
    else{
        if(index != 0){
            midRes[index] = '0'; midRes[midRes.size() - 1 - index] = '0';
            dfs(res, index + 1, midRes);
        }
        midRes[index] = '1'; midRes[midRes.size() - 1 - index] = '1';
        dfs(res, index + 1, midRes);
        midRes[index] = '6'; midRes[midRes.size() - 1 - index] = '9';
        dfs(res, index + 1, midRes);
        midRes[index] = '9'; midRes[midRes.size() - 1 - index] = '6';
        dfs(res, index + 1, midRes);
        midRes[index] = '8'; midRes[midRes.size() - 1 - index] = '8';
        dfs(res, index + 1, midRes);
    }
}

vector<string> findStrobogrammatic(int n)
{
    vector<string> res;
    string midRes(n, '0');
    dfs(res, 0, midRes);

    return res;
}

int main()
{
    PrintVector(findStrobogrammatic(1));
}
