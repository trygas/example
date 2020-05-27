#include "general.h"

bool count(map<char, int> &m, int k)
{
    int max = 0;
    int sum = 0;
    for(auto iter: m){
        sum += iter.second;
        max = std::max(iter.second, max);
    }

    if(max + k >= sum)
        return true;
    else
        return false;
}

int characterReplacement(string &s, int k)
{
    int left = 0, right = 0;
    int res = 0;
    map<char, int> m;

    while(right < s.size())
    {
        m[s[right]]++;
        while(!count(m, k)){
            m[s[left]]--;
            left++;
        }
        res = std::max(res, right - left + 1);
        right++;
    }

    return res;
}