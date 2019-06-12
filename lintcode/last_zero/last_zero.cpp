#include <iostream>

int main()
{
    int n = 10;
    int res = 0;

    // 5的倍数会产生一个结果中0的数字
    // 但是25的倍数会返回多个0
    while(n)
    {
        n = n / 5;
        res += n;
    }

    std::cout << res;
    return 0;
}