#include "general.h"

/*
 * 思路就是构建一个数组res
 * res[i]代表0-i的string有多少个
 * 然后新增一个字母就遍历之前的res
 */
int main()
{
    string s = "CatMat";
    vector<string> dict = {"Cat", "Mat", "Ca", "tM", "at", "C", "Dog", "og", "Do"};

    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    unordered_set<string> lower_dict;
    for(auto word: dict){
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        lower_dict.insert(word);
    }

    int n = s.size();
    vector<int> res(n+1, 0);
    res[0] = 0;
    for(int i = 1; i <= n; ++i){
        res[i] = lower_dict.count(s.substr(0, i)) ? 1 : 0;
        for(int j = 0; j < i; ++j){
            string cmp = s.substr(j, i - j);
            if (lower_dict.count(cmp))
                res[i] += res[j];
        }
    }

    PrintVector(res);
}