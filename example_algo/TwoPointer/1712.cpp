#include "general.h"

int numSubarraysWithSum(vector<int> &A, int S)
{
    int res = 0;
    int sum = 0;
    map<int, int> m;
    m[0] = 1;

    for(int i: A){
        sum += i;
        res += m[sum - S];
        m[sum]++;
    }

    return res;
}

int main()
{
    vector<int> A = {0,0,0,0,0,0,1,0,0,0};
    int S = 0;

    return numSubarraysWithSum(A, S);
}