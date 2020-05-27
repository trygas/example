#include "general.h"

/*
 * 主要思路是计算两个单词的最长公共子序列
 */
int main()
{
    string word1 = "horse", word2 = "ros";

    vector<vector<int > > res(word1.size() + 1, vector<int>(word2.size() + 1, 0));
    for(int i = 1; i <= word1.size(); ++i){
        for(int j = 1; j <= word2.size(); ++j){
            if(word1[i - 1] == word2[j - 1]){
                res[i][j] = res[i - 1][j - 1] + 1;
            }
            else{
                res[i][j] = std::max(res[i - 1][j], res[i][j - 1]);
            }
        }
    }

    return word1.size() + word2.size() - 2 * res[word1.size()][word2.size()];
}
