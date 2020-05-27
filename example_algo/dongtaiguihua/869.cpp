#include "general.h"

int main(int argc, char *argv[])
{
    int n  = 20;

    vector<int> res (n + 1, 0);
    res[2] = 1;
    for(int i = 3; i <= n; ++i){
        res[i] += ((i - 1) * (res[i - 2] + res[i - 1])) % 1000000007;
    }

    PrintVector(res);
    return 0;
}
