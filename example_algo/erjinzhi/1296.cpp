#include "general.h"

int maxProduct(vector<string> &words)
{
    map<int, long long> m;
    for(int i = 0; i < words.size(); ++i){
        int res = 0;
        for(int j = 0; j < words[i].size(); ++j){
            res = res | (1 << (words[i][j] - 'a'));
        }

        m[i] = res;
    }

    int res = 0;
    for(int i = 0; i < words.size(); ++i){
        for(int j = i + 1; j < words.size(); ++j){
            if(m[i] & m[j])
                continue;
            res = std::max((int)(words[i].size() * words[j].size()), res);
        }
    }

    return res;
}

int main()
{
    vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    cout << maxProduct(words);
}
