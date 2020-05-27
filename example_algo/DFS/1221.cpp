#include "general.h"

vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
{
    set<string> hash(words.begin(), words.end());
    vector<string> res;
    for(string w: words){
        int n = w.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for(int i = 0; i < n; ++i){
            if(dp[i] == 0)
                continue;
            for(int j = i + 1; j <= n; ++j){
                if(j - i < n && hash.count(w.substr(i, j - i)))
                    dp[j] = true;
            }
            if(dp[n]){
                res.push_back(w);
                break;
            }
        }
    }
    return res;
}

int main()
{
    vector<string> words = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
    PrintVector(findAllConcatenatedWordsInADict(words));
}
