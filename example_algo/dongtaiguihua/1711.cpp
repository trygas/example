#include "general.h"

/*
 * 这个题的思路就是创建一个二维数组, A
 * 其中A[i][j]代表着从第一行到num[i][j]的最小距离
 */
int main()
{
    vector<vector<int > > num = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9,}};
    vector<vector<int > > res(num.size() + 1, vector<int>(num[0].size() + 1, 0));

    for(int i = 1; i <= num.size(); ++i){
        for(int j = 1; j <= num[i - 1].size(); ++j){
            if(j!=1 && j!=num[i - 1].size())
                res[i][j] =
                    std::min(res[i-1][j-1], std::min(res[i-1][j], res[i-1][j+1])) + num[i-1][j-1];
            else if(j == 1)
                res[i][j] = std::min(res[i-1][j], res[i-1][j+1]) + num[i-1][j-1];
            else
                res[i][j] = std::min(res[i-1][j-1], res[i-1][j]) + num[i-1][j-1];
        }
    }

    PrintVectorVector(res);
}
