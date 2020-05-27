#include "general.h"

/*
 * swap[i]代表第i个元素进行交换, 使A,B严格单调递增的最小交换个数
 * keep[i]代表第i个元素不进行交换,使A,B严格单调递增的最小交换个数
 *
 * 所以就要判断A[i]>A[i-1],B[i]>B[i-1]和A[i]>B[i-1],B[i]>A[i-1]这两种情况
 */
int main()
{
    vector<int> num1 = {1, 3, 5, 5};
    vector<int> num2 = {1, 2, 3, 7};
    int len = num1.size();

    vector<int> swap(len, 0x3f3f3f3f), keep(len, 0x3f3f3f3f);
    swap[0] = 1;
    keep[0] = 0;
    for(int i = 1; i < len; ++i){
        if (num1[i] > num1[i - 1] && num2[i] > num2[i - 1]){
            keep[i] = keep[i - 1];
            swap[i] = swap[i - 1] + 1;
        }
        if (num1[i] > num2[i - 1] && num2[i] > num1[i - 1]){
            keep[i] = std::min(swap[i - 1], keep[i]);
            swap[i] = std::min(swap[i], keep[i - 1] + 1);
        }
    }

    cout << std::min(swap[len - 1], keep[len - 1]);
}
