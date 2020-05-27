#include "general.h"

int computeLastDigit(long long A, long long B)
{
    int res = 1;
    for(long long i = A + 1; i <= B; ++i){
        string num = to_string(i);

        int theRes = num[num.size() - 1] - '0';
        res = (theRes * res) % 10;
        if(res == 0)
            return 0;
    }

    return res;
}

int main()
{
    long long A = 107, B = 109;
    cout << computeLastDigit(A, B);
}
