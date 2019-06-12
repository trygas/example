#include "general.h"

#include <boost/bind/bind.hpp>
#include <functional>

int sum(int a, int b)
{
    return a + b;
}

int main()
{
    function<int(int, int)> function1 = bind(sum, placeholders::_1, placeholders::_2);
    cout << function1(1, 2);
}