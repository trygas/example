#include "general.h"

int Find(vector<int> &A, int num)
{
    int l = 0, r = A.size() - 1;
    int res = -1;
    while(r >= l){
        int mid = (l + r) / 2;
        if(A[mid] >= num)
            r = mid - 1;
        else{
            l = mid + 1;
            res = mid;
        }
    }

    return res + 1;
}

int main()
{
    vector<int> A = {1, 2, 7, 8, 5};
    vector<int> queries = {1, 8, 5};

    sort(A.begin(), A.end());
    vector<int> res;
    for(int i = 0; i < queries.size(); ++i)
        res.push_back(Find(A, queries[i]));
}
