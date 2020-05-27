#include "general.h"

/*
 * 这个题的思路可以是快排, 只不过要选择中间点
 * 下面这个思路就是计算每个数字各有几个值.
 */
vector<int> sort(vector<int> &num, int target)
{
    std::vector<int> res(target + 1, 0);
    for(int i = 0; i < num.size(); ++i){
        res[num[i]]++;
    }

    std::vector<int> ans(num.size(), 0);
    int index = 0;
    for(int i = 1; i < res.size(); ++i){
        for(int j = 0; j < res[i]; ++j){
            ans[index++] = i;
        }
    }

    return ans;
}

int main()
{
    vector<int> num = {3, 2, 2, 1, 4};
    int target = 4;
    vector<int> ans = sort(num, target);
    PrintVector(ans);
}
