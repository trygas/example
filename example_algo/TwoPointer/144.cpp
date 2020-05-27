#include "general.h"

int main()
{
    vector<int> A = {-1, -2, -3, 4, 5, 6};

    sort(A.begin(), A.end());
    int gap = 0;
    for(int i = 0; i < A.size(); ++i){
        if(A[i] > 0){
            gap = i;
            break;
        }
    }
    if(A.size() % 2 != 0 && gap == A.size() / 2)
        reverse(A.begin(), A.end());

    int left = 1, right = A.size() - 1;
    if(A.size() % 2 == 0){
        right = A.size() - 2;
    }
    while(left < right){
        swap(A[left], A[right]);
        left += 2;
        right -= 2;
    }

    PrintVector(A);
}