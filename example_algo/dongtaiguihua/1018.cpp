#include "general.h"

/*
 * 这个题目的思想就是一级一级的判断是否当前杯子是否满了
 * 然后如果满了则将多余的酒倒入下一层.
 */
int main()
{
    int poured = 1000000000, query_row = 99, query_glass = 99;

    vector<vector<double> > res(101, vector<double>(101, 0));
    res[0][0] = poured;

    for(int i = 0; i <= query_row; ++i){
        for(int j = 0; j <= i; ++j){
            double next = (res[i][j] - 1.0) / 2.0;
            if (next > 0){
                res[i+1][j] += next;
                res[i+1][j+1] += next;
            }
        }
    }

    cout << (res[query_row][query_glass] > 1) ? 1 : res[query_row][query_glass];
}
