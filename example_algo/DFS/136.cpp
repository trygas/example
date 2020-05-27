#include "general.h"

/*
 * 思路就是用回溯法枚举所有的可能
 */
bool isPalindrome(const string &s)
{
    for(int l = 0, r = s.size() - 1; l < r; ++l, --r){
        if (s[l] != s[r])
            return false;
    }
    return true;
}

void Handle(const string &str, vector<vector<string> > &res,
            vector<string> &midRes)
{
    int n = str.size();
    if (n == 0){
        res.emplace_back(midRes);
        return;
    }

    for(int i = 0; i < n; ++i){
        if (isPalindrome(str.substr(0, i + 1))){
            midRes.emplace_back(str.substr(0, i + 1));
            Handle(str.substr(i + 1), res, midRes);
            midRes.pop_back();
        }
    }
}

int main()
{
    string s = "abbab";

    vector<vector<string> > res;
    vector<string> midRes;
    Handle(s, res, midRes);
    PrintVectorVector(res);
}
