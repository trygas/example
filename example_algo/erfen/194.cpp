#include "general.h"

bool Check(string &s, vector<vector<int> > &word)
{
    int tmp = -1;
    for(int i = 0; i < s.size(); ++i){
        if(word[s[i] - 96].empty())
            return false;
        auto it = upper_bound(word[s[i] - 96].begin(), word[s[i] - 96].end(), tmp);
        if(it != word[s[i] - 96].end()){
            tmp = *it;
        }
        else
            return false;
    }
    return true;
}

vector<string> findWords(string &str, vector<string> &dict)
{
    vector<vector<int> > word(27, vector<int>());
    vector<string> ans;

    for(int i = 0; i < str.size(); ++i){
        word[str[i] - 96].push_back(i);
    }

    for(int i = 0; i < dict.size(); ++i){
        string s = dict[i];

        if(Check(s, word))
            ans.push_back(s);
    }

    return ans;
}

int main()
{
    string str = "bcogtadsjofisdhklasdj";
    vector<string> dict = {"book","code","tag"};
    PrintVector(findWords(str, dict));
}
