#include "general.h"

/*
 * 这个题目的重点是prices是不能复用的
 * 所以这个题目要构建一个二维数组res
 * res[i][j]代表前i个prices有j钱的时候的最大概率
 */
int main(int argc, char *argv[])
{
    int n = 10;
    vector<int> prices = {4, 4, 5};
    vector<double> probability = {0.1, 0.2, 0.3};

    vector<double> invProbability;
    for(int i = 0; i < probability.size(); ++i){
        invProbability.emplace_back(1.0 - probability[i]);
    }
    vector<double> res(n + 1, 1);
    for(int i = 0; i < invProbability.size(); ++i){
        // 从后往前保证不会使用重复的prices[i]
        for(int j = n; j >= prices[i]; --j){
            res[j] = std::min(res[j], res[j - prices[i]] * invProbability[i]);
        }
    }

    PrintVector(res);
    return 0;
}

