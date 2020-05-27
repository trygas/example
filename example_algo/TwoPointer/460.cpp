#include "general.h"

int main()
{
    vector<int> A = {1, 2, 3};
    int target = 2, k = 3;

    int index = 0, gap = std::abs(A[0] - target);
    for(int i = 0; i < A.size(); ++i){
        int newGap = std::abs(A[i] - target);
        if(gap > newGap){
            index = i;
            gap = newGap;
        }
    }

    vector<int> res;
    k--;
    int left = index-1, right = index+1;
    res.push_back(A[index]);
    while(k){
        if(left >= 0 && right <= A.size() - 1){
            int leftGap = std::abs(A[left] - target);
            int rightGap = std::abs(A[right] - target);
            if(leftGap == rightGap || leftGap < rightGap){
                res.push_back(A[left]);
                left--;
            }
            else{
                res.push_back(A[right]);
                right++;
            }
            k--;
        }
        else if(left < 0 && right <= A.size() - 1){
            res.push_back(A[right]);
            right++;
            k--;
        }
        else if(right > A.size() - 1 && left >= 0){
            res.push_back(A[left]);
            left--;
            k--;
        }
    }

    PrintVector(res);
}