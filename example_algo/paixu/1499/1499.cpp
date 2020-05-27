#include "general.h"

/*
 * 这个题的主要思路就是判断目标数字排序后是不是在2的n次方的数字排序中
 */
int main()
{
    map<int, std::vector<int> > m;
    int num = 1;
    while(to_string(num).size() < 10){
        m[to_string(num).size()].emplace_back(num);
        num *= 2;
    }

    int target = 3;
    string targetStr = to_string(target);
    sort(targetStr.begin(), targetStr.end());
    int len = to_string(target).size();
    for(int i = 0; i < m[len].size(); ++i){
        string str = to_string(m[len][i]);
        sort(str.begin(), str.end());
        if (targetStr == str)
            return true;
    }

    return false;
}
