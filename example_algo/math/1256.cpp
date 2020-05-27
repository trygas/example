#include "general.h"

int findNthDigit(int n) {
    // write your code here
    // 初始化一位数的个数有9个，从1开始
    long long len = 1, cnt = 9, start = 1;
    while (n > len * cnt) {
        // 以此类推二位数的个数有90个，从10开始
        n -= len * cnt;
        ++len;
        cnt *= 10;
        start *= 10;
    }
    // 找到第n位在整数start当中
    start += (n - 1) / len;
    string t = to_string(start);
    return t[(n - 1) % len] - '0';
}


int main()
{
    int n = 11;
    cout << findNthDigit(n);
}
