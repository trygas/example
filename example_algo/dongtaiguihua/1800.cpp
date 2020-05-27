#include "general.h"

vector<int> getArray(vector<double> &A, int target)
{
    vector<double> res(target + 1, INT32_MAX);

    res[0] = 0;
    for(int i = 0; i < A.size(); ++i){
        int left = (int)A[i];
        int right = left + 1;
        if(left == A[i])
            right = left;

        for(int j = target; j >= left; --j){
            if(res[j - left] != INT32_MAX)
                res[j] = std::min(res[j], A[i] - left + res[j - left]);
            if(res[j - right] != INT32_MAX)
                res[j] = std::min(res[j], right - A[i] + res[j - right]);
        }
    }

    cout << res[target];
    return {};
}

int main()
{
    vector<double> A = {1.2,1.3,2.3,4.2};
    int target = 9;

    getArray(A, target);
}
