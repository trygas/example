#include "general.h"

/*
 * 这个题目的思路就是固定一个根节点,剩下的节点放入左子树和右子树
 */
int main()
{
    int n = 3;

    vector<int> res(n + 1, 0);
    res[1] = 1;
    res[0] = 1;
    for(int i = 2; i <= n; ++i){
        for(int j = 0; j <= i - 1; ++j){
            res[i] += res[j] * res[i - 1 - j];
        }
    }

    PrintVector(res);
}
