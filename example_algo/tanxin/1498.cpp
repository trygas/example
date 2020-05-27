#include "general.h"

int main()
{
    vector<int> A = {2, 7, 11, 15};
    vector<int> B = {1, 10, 4, 11};

    sort(A.begin(),A.end());
    vector<int> result;

    for(auto &i : B){
        auto ub = upper_bound(A.begin(),A.end(),i);

        if(ub == A.end()){
            result.push_back(*A.begin());
            A.erase(A.begin());
        }else{
            result.push_back(*ub);
            A.erase(ub);
        }
    }
}