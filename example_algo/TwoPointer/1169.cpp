#include "general.h"

bool MapEqual(map<char, int> &s1, map<char, int> &s2){
    for(auto &iter: s1){
        char c = iter.first;
        if(iter.second != s2[c])
            return false;
    }
    return true;
}

int main()
{
    string s1 = "ab", s2 = "eidbaooo";

    map<char, int> countS1;
    map<char, int> countS2;
    for(auto &c: s1)
        countS1[c]++;

    for(int i = 0; i < s1.size(); ++i){
        countS2[s2[i]]++;
    }
    for(int i = 0; i < s2.size() - s1.size() + 1; ++i){
        if(MapEqual(countS1, countS2))
            return true;
        countS2[s2[i]]--;
        countS2[s2[i + s1.size()]]++;
    }
    return false;
}