#include "general.h"

/*
 * 这个题目lintcode应该是错误的.
 * 主要就是保存第i个骰子投出的数字后的数字和.
 */
vector<pair<int, double> > handle(int n)
{
    map<int, map<int, int> > m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < 7; ++j){
            if (i == 1){
                pair<int, int> p = {i, i};
                m[i][j]++;
            }
            else{
                for(auto &vec: m[i - 1]){
                    m[i][vec.first + j]++;
                }
            }
        }
    }

    int sum = 0;
    for(auto &vec: m[n]){
        sum += vec.second;
    }

    vector<pair<int, double> > res;
    for(auto &vec: m[n]){
        res.emplace_back(make_pair(vec.first, double(vec.second) / sum));
    }
    return res;
}

int main()
{
    int n = 3;
    vector<pair<int, double> > ans = handle(n);
    PrintVectorPair(ans);
}
