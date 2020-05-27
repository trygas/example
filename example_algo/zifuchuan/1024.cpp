#include "general.h"

bool isSubseq(string &word, vector<vector<int> > &nxtPos)
{
    int lenw = word.size();
    int lens = nxtPos.size();
    int i = 0, j = 0;
    for(; i < lenw && j < lens; ++i, ++j){
        j = nxtPos[j][word[i] - 'a'];
        if(j < 0)
            return 0;
    }

    return i == lenw;
}

int main()
{
    string S = "abcde";
    vector<string> words = {"a", "bb", "acd", "ace"};

    int n = S.size();
    vector<vector<int> > nxtPos;
    vector<int> tmp(26, -1);
    for(int i = n - 1; i >= 0; --i){
        tmp[S[i] - 'a'] = i;
        nxtPos.push_back(tmp);
    }

    reverse(nxtPos.begin(), nxtPos.end());

    int ans = 0;
    for(string &word: words){
        if(isSubseq(word, nxtPos))
            ans++;
    }

    return ans;
}