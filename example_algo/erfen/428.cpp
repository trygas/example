#include "general.h"

double pow(double &x, long long n)
{
    if(n == 0)
        return 1.0;
    double temp = pow(x, n / 2);
    if(n % 2 == 0)
        return temp * temp;

    return temp * temp * x;
}

int main()
{
    double x = 9.88023;
    int n = 3;

    if(n < 0){
        x = 1 / x;
        n = -n;
    }
    cout << pow(x, n);
}
