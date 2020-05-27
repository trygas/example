#include "general.h"

vector<string> getValues(const string &s)
{
    vector<string> ret;
    if(s.length() == 1 || s[0] != '0')
        ret.push_back(s);

    for(int i = 1; i < s.length(); ++i){
        string integer = s.substr(0, i);
        string fractor = s.substr(i);
        if(integer.length() > 1 && integer[0] == '0')
            continue;
        if(stoi(fractor) == 0 || fractor.back() == '0')
            continue;

        ret.push_back(integer + '.' + fractor);
    }

    return ret;
}

int main()
{
    string S = "(00011)";
    S = S.substr(1, S.length() - 2);
    vector<string> ret;

    for(int i = 1; i < S.length(); ++i){
        string s1 = S.substr(0, i);
        string s2 = S.substr(i);
        if((s1.length() > 1 && stoi(s1) == 0) ||
           (s2.length() > 1 && stoi(s2) == 0))
            continue;

        vector<string> integers = getValues(s1);
        vector<string> fractors = getValues(s2);
        for(int i = 0; i < integers.size(); ++i){
            for(int j = 0; j < fractors.size(); ++j){
                ret.push_back("(" + integers[i] + ", " + fractors[j] + ")");
            }
        }
    }

    PrintVector(ret);
}