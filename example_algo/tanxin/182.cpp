#include "general.h"

/*
 * 主要思路是第i次去除数字的最小值是第i-1次去除数字的值再除去一个数字
 * 且除去数字的策略是只要后一位数字小于当前数字则去除当前数字即可
 */
string remove(string A, int pos) {
    return A.substr(0, pos) + A.substr(pos + 1, A.length() - pos - 1);
}

int main()
{
    string A = "178542";
    int k = 4;

    if (A.length() == k) {
        cout << "";
        return 0;
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < A.length(); j++) {
            if (j == A.length() - 1 || A[j + 1] < A[j]) {
                A = remove(A, j);
                break;
            }
        }
    }

    int i = 0;
    while (i < A.length() - 1 && A[i] == '0') {
        i++;
    }
    cout << A.substr(i, A.length() - i);
}