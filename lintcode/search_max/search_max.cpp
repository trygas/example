#include "general.h"

int findPeak(vector<int>& A) {
    // write your code here
    int start=1,end=A.size()-2;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(A[mid]>A[mid+1])
        {
            if(A[mid]>A[mid-1])
                return mid;
            else end=mid-1;//左侧存在峰值
        }
        else start=mid+1;//右侧存在峰值
    }
    return -1;
}
int main()
{
    vector<int> data = {1,2,1,2,3,1};

    cout << findPeak(data);
}