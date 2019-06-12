#include "general.h"

int search(vector<int> &A, int target) {
    // write your code here
    if(A.empty()) return -1;
    int start = 0;
    int end = A.size() - 1;
    while(start + 1 < end)
    {
        int mid = start + (end - start) /2;
        if(A[mid] == target) return mid;
        if(A[mid] < A[end])
        {
            if(A[mid] < target && A[end] >= target)
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        if(A[mid] > A[end])
        {
            if(A[mid] >target && A[start] <= target)
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }
    }
    if(A[start] == target) return start;
    if(A[end] == target) return end;
    return -1;
}

int main()
{
    vector<int> data = {4, 5, 1, 2, 3};
    int target = 0;

    cout << search(data, target);
}