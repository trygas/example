#include "general.h"

int main()
{
    string s = "lintcode";
    unordered_set<string> dict = {"lint", "code"};

    int n = s.size();
    vector<bool> res(n + 1, 0);
    res[0] = true;
    for(int i = 1; i <= n; ++i){
        for(int j = i - 1; j >= 0; --j){
            string str = s.substr(j, i - j);
            if (dict.count(str) && res[j]){
                res[i] = true;
                break;
            }
        }
    }

    PrintVector(res);
}

