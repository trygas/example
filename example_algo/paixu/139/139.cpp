#include "general.h"

struct node{
    node(int _value, int _pos): value(_value), pos(_pos){}
    bool operator < (const node& o) const {
        return (value < o.value || value == o.value && pos < o.pos);
    }
    int value;
    int pos;
};

/*
 * 主要思路是累加num的数字生成一个数组
 * sum[i]为前i个数字的和.
 * 将sum数组进行排序.
 * 然后num[i]-num[i-1]就是i-1的pos+1到pos
 */
vector<int> handle(std::vector<int> &num, int target)
{
    std::vector<node> numSum;
    std::vector<int> res(2);
    int sum = 0;
    numSum.emplace_back(node(0, -1));
    for(int i = 0; i < num.size(); ++i){
        sum += num[i];
        numSum.emplace_back(node(sum, i));
    }

    sort(numSum.begin(), numSum.end());
    int ans = INT32_MAX;
    for(int i = 0; i < numSum.size() - 1; ++i){
        if (abs(numSum[i + 1].value - numSum[i].value) < ans){
            ans = abs(numSum[i + 1].value - numSum[i].value);
            res[0] = min(numSum[i].pos, numSum[i + 1].pos) + 1;
            res[1] = max(numSum[i].pos, numSum[i + 1].pos);
        }
    }

    return res;
}

int main()
{
    int target = 0;
    vector<int> num = {3,-3,5};

    vector<int> res = handle(num, target);
    PrintVector(res);
}
