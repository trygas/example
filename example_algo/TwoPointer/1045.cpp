#include "general.h"

/*
 * 思路是首先遍历字符串, 找出所有字母的最后一位位置
 * 然后再次遍历字符串, 如果已经到了当前字母的最后位置,
 * 且之前的字母的最后位置小于当前位置, 则可以分割
 */
int main()
{
    string S = "ababcbacadefegdehijhklij";

    map<char, int> indexRight;
    for(int i = 0; i < S.size(); ++i){
        indexRight[S[i]] = i;
    }
    vector<int> res;
    int left = 0, right = 0;
    for(int i = 0; i < S.size(); ++i){
        right = std::max(right, indexRight[S[i]]);
        if(i == right){
            res.push_back(i - left + 1);
            left = i + 1;
        }
    }

    PrintVector(res);
}