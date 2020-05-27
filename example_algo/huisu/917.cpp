#include "general.h"

void Handle(string &s, int start, string mid,
            unordered_set<string> &res)
{
    if(start >= s.size())
        res.insert(s + mid + string(s.rbegin(), s.rend()));

    for(int i = start; i < s.size(); ++i){
        if(i != start && s[i] == s[start])
            continue;
        swap(s[i], s[start]);
        Handle(s, start + 1, mid, res);
        swap(s[i], s[start]);
    }
}

int main()
{
    string s = "aaaabbbb";

    unordered_map<char, int> m;
    unordered_set<string> res;
    string t = "", mid = "";
    for(auto a: s) m[a]++;
    for(auto it: m){
        if(it.second % 2 == 1)
            mid += it.first;
        t += string(it.second / 2, it.first);
        if(mid.size() > 1)
            return 0;
    }

    Handle(t, 0, mid, res);
    PrintVector(vector<string>(res.begin(), res.end()));
}