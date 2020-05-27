#include "general.h"

struct block{
    block(){
        maxNum = INT32_MIN;
        minNum = INT32_MAX;
    }

    int maxNum;
    int minNum;
};

/*
 * 主要思路就是排序后的最大间距肯定是大于等于平均距离的,
 * 所以有多少数字就生成多少桶, 然后每个桶里面只需要维护最大值和最小值.
 */
int handle(vector<int> &num)
{
    int min = INT32_MAX, max = -1;
    int len = num.size();
    for(int i = 0; i < num.size(); ++i){
        min = std::min(min, num[i]);
        max = std::max(max, num[i]);
    }

    std::vector<block> blocks(len);
    int avegap = std::ceil((max - min) / (len - 1));
    for(int i = 0; i < num.size(); ++i){
        //特殊情况, 只有最大值和最小值
        if (num[i] == max || num[i] == min)
            continue;
        int index = (num[i] - min) / avegap;
        blocks[index].minNum = std::min(blocks[index].minNum, num[i]);
        blocks[index].maxNum = std::max(blocks[index].maxNum, num[i]);
    }

    // 同一组内的最大最小值差值不会是最大的
    int res = 0;
    int lastMax = min;
    for(int i = 0; i < blocks.size(); ++i){
        if (blocks[i].minNum == INT32_MAX || blocks[i].maxNum == INT32_MIN)
            continue;
        res = std::max(res, blocks[i].minNum - lastMax);
        lastMax = blocks[i].maxNum;
    }
    res = std::max(max - lastMax, res);

    return res;
}

int main()
{
    vector<int> num = {999,999,999,999,999,999,999,999,999,999};
    cout << handle(num);
}
