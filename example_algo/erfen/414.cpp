#include "general.h"

int divide(int dividend, int divisor) {
    if (!dividend)
        return 0;
    if (!divisor)
        return 2147483647;

    int sign = (dividend > 0) == (divisor > 0) ? 1 : -1;

    long long a = llabs(dividend), b = llabs(divisor), res = 0;
    while (a >= b) {
        for (long long c = b, cnt = 1; a >= c; c <<= 1, cnt <<= 1) {
            a -= c;
            res += cnt;
        }
    }

    if (res == 2147483648 && sign > 0)
        return 2147483647;

    return sign * res;
}

int main()
{
    int dividend = -2147483648, divisor = 1;
    cout << divide(dividend, divisor);
}
