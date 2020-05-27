#include "general.h"

int knightDialer(int N) {
    vector<vector<unsigned int> > res(N +  1, vector<unsigned int>(10, 0));
    int mod = pow(10, 9) + 7;

    for(int i = 0; i < 10; ++i)
        res[1][i] = 1;

    for(int i = 2; i <= N; ++i){
        res[i][0] = res[i - 1][6] + res[i - 1][4];
        res[i][1] = res[i - 1][6] + res[i - 1][8];
        res[i][2] = res[i - 1][9] + res[i - 1][7];
        res[i][3] = res[i - 1][4] + res[i - 1][8];
        res[i][4] = res[i - 1][3] + res[i - 1][9] + res[i - 1][0];
        res[i][5] = 0;
        res[i][6] = res[i - 1][0] + res[i - 1][1] + res[i - 1][7];
        res[i][7] = res[i - 1][2] + res[i - 1][6];
        res[i][8] = res[i - 1][1] + res[i - 1][3];
        res[i][9] = res[i - 1][2] + res[i - 1][4];

        for(int j = 0; j < 10; ++j){
            res[i][j] = res[i][j] % mod;
        }
    }

    int sum = 0;
    for(int i = 0; i < 10; ++i){
        sum = (sum + res[N][i]) % mod;
    }
    return sum;
}

int main()
{
    cout << knightDialer(111);
}