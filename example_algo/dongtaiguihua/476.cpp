#include "general.h"

/*
 * 这个题目的思路就是要构建与一个二维数组res
 * res[i][j]代表石头i到j我们要花费的最小代价
 * 然后就要在一个区间中分别枚举长度
 * 在这个长度下分隔区间,查找区间中的最小值
 */
int main()
{
    vector<int> A = {4, 1, 1, 4};

    int n = A.size();
    vector<vector<int > > res(n + 1, vector<int>(n + 1, 0));
    vector<int > sum(n + 1, 0);

    for(int i = 1; i <= n; ++i){
        res[i][i] = 0;
        sum[i] = sum[i - 1] + A[i - 1];
    }
    for(int i = 2; i <= n; ++i){
        for(int j = 1; j <= n - i + 1; ++j){
            int k = i + j - 1;
            res[j][k] = INT32_MAX;
            for(int m = j; m < k; ++m){
                if (res[j][k] > res[j][m] + res[m + 1][k] + sum[k] - sum[j - 1])
                    res[j][k] = res[j][m] + res[m + 1][k] + sum[k] - sum[j - 1];
            }
        }
    }

    PrintVectorVector(res);
}
