#include "general.h"

/*
 * 主要就是定义了一个res二维数组,
 * res[i][0]表示尾端没有多余,就是说一共有2Xi块各自
 * res[i][1]表示上面那一行多出来了一块,就是上面i+1个格子,下面有i个格子
 * res[i][2]表示下面一行多了一块,上面有i个格子,下面有i+1个格子.
 */
int main()
{
    int num = 5;

    vector<vector<long long > > res(num + 1, vector<long long>(3, 0));
    res[0][0] = 1;
    res[1][0] = 1;
    res[1][1] = 1;
    res[1][2] = 1;
    for(int i = 2; i <= num; ++i){
        res[i][0] = (res[i - 1][0] + res[i - 2][0] + res[i - 2][1] + res[i - 2][2]);
        res[i][1] = (res[i - 1][0] + res[i - 1][2]);
        res[i][2] = (res[i - 1][0] + res[i - 1][1]);
    }

    PrintVectorVector(res);
}
