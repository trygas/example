#include "general.h"

int leastInterval(string &tasks, int n) {
    // write your code here
    unordered_map<char,int> count;
    auto maxcount=0;
    for(auto c:tasks)
        maxcount=max(maxcount, ++count[c]);
    auto result=(n+1) *(maxcount-1);
    for(auto c:count)
        if(c.second==maxcount)
            ++result;
    return max(result,(int)tasks.length());
}
