#include "general.h"

int main()
{
    int num = 10;
    vector<int > res(num + 1, 0);
    res[1] = 1;

    for(int i = 2; i <= num; ++i){
        res[i] = i;
        if (i == num)
            res[i] = 0;
        for(int j = 1; j < i; ++j)
            res[i] = std::max(res[i], res[i - j] * j);
    }

    PrintVector(res);
}
