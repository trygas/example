#include "general.h"

int main()
{
    vector<int> A = {2, 3, 1, 1, 4};

    vector<int> res(A.size() + 1, INT32_MAX);
    res[0] = 0;
    res[1] = 0;
    for(int i = 0; i < A.size(); ++i){
        for(int j = 1; j <= A[i]; ++j){
            if(i + 1 + j < res.size())
                res[i + 1 + j] = std::min(res[i + 1 + j], res[i + 1] + 1);
        }
    }

    PrintVector(res);
}
