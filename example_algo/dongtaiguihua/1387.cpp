#include "general.h"

int numFactoredBinaryTrees(vector<int> &A)
{
    int n = A.size();
    sort(A.begin(), A.end());
    set<int> count(A.begin(), A.end());
    vector<int> res(n, 1);

    long sum = res[0], mod = pow(10, 9) + 7;
    for(int i = 1; i < A.size(); ++i){
        for(int j = i - 1; j >= 0; --j){
            if(A[i] % A[j] == 0){
                int left = A[i] / A[j];
                if(count.count(left) != 0)
                    res[i] += res[j];
            }
        }
        sum = (sum + res[i]) % mod;
    }

    return sum;
}

int main()
{
    vector<int> A = {2, 4, 5, 10};

    cout << numFactoredBinaryTrees(A);
}
