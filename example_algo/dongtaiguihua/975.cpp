#include "general.h"

int main()
{
    int n = 6;

    vector<int> res(n+1, INT32_MAX);
    res[1]=0;
    for(int i = 2; i <= n; ++i){
        for(int j = i-1; j >= 1; --j){
            if(i % j == 0){
                res[i] = std::min(res[i], res[j]+i/j);
            }
        }
    }

    PrintVector(res);
}
