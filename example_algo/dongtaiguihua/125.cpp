#include "general.h"

/*
 * 主要思路是创建一个二维数组，代表着i个数和j重量最大的价值。
 */
int main()
{
    int m = 10;
    vector<int> num = {2, 3, 5, 7};
    vector<int> value = {1, 5, 2, 4};
    vector<vector<int> > res(num.size() + 1, vector<int>(m + 1, 0));

    for(int i = 0; i <= num.size(); ++i){
        for(int j = 0; j <= m; ++j){
            if (i == 0 || j == 0){
                res[i][j] = 0;
                continue;
            }
            int heavy = num[i - 1];
            int v = value[i - 1];

            if (heavy > j)
                res[i][j] = res[i - 1][j];
            else
                res[i][j] = std::max(res[i - 1][j - heavy] + v, res[i - 1][j - 1]);
        }
    }

    cout << res[num.size()][m];
}

