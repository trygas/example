#include "general.h"

//void dfs(string &s, unordered_set<string> &wordDict,
//         vector<string> &res, string midRes)
//{
//    if(wordDict.count(s)){
//        if(midRes.empty())
//            res.push_back(s);
//        else
//            res.push_back(midRes + " " + s);
//    }
//
//    for(int i = 1; i <= s.size(); ++i){
//        string nowRes = midRes;
//        string left = s.substr(0, i);
//        string right = s.substr(i);
//        if(wordDict.count(left)){
//            if(nowRes.empty())
//                nowRes = left;
//            else
//                nowRes = nowRes + " " + left;
//            dfs(right, wordDict, res, nowRes);
//        }
//    }
//}

vector<string> res;
vector<int> f[5000];
int m;

void dfs(int p, string s, string now)
{
    if(p == m){
        res.push_back(now);
        return;
    }

    if(p > 0)
        now += " ";

    for(int i = 0; i < f[p].size(); ++i)
        dfs(f[p][i], s, now + s.substr(p, f[p][i] - p));
}

vector<string> wordBreak(string &s, unordered_set<string> &wordDict)
{
    m = s.size();

    for(int i = m - 1; i >= 0; --i){
        for(int j = i + 1; j <= m; ++j){
            if(wordDict.find(s.substr(i, j - i)) != wordDict.end())
                if(j == m || f[j].size() > 0)
                    f[i].push_back(j);
        }
    }

    dfs(0, s, "");
    return res;
}

int main()
{
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    unordered_set<string> wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};

    wordBreak(s, wordDict);
    PrintVector(res);
}
