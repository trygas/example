#include "general.h"

void dfs(string &s, vector<string> &res, string midRes,
         int sum, int target, int last, int start)
{
    if(s.size() == start){
        if(sum == target)
            res.push_back(midRes);

        return;
    }

    long long x = 0;
    string ret = "";
    for(int i = start; i < s.size(); ++i){
        x = x * 10 + s[i] - '0';
        ret += s[i];

        if(start == 0)
            dfs(s, res, midRes + ret, x, target, x, i + 1);
        else{
            dfs(s, res, midRes + "*" + ret, sum - last + x * last, target, x * last, i + 1);
            dfs(s, res, midRes + "+" + ret, sum + x, target, x, i + 1);
            dfs(s, res, midRes + "-" + ret, sum - x, target, -x, i + 1);
        }

        if(x == 0)
            break;
    }
}

vector<string> addOperators(string &num, int target)
{
    vector<string> res;
    dfs(num, res, "", 0, target, 0, 0);
    return res;
}

