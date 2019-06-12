//
// Created by liu on 18-8-19.
//

#include <iostream>

using namespace std;

int main()
{
    int k = 0;
    int n = 54321;

    int rest = 0;
    int count = 0;
    int time = 1;
    int last = 0;

    if (n == 0 && k == 0)
        return 1;

    if(n < 10 && n > k)
    {
        return 1;
    }

    while(n > 0)
    {
        n = n / 10;
        rest = n % 10;

        if (n == 0 && k == 0)
        {
            return count;
        }

        if(rest > k)
        {
            count += (n + 1) * time;
        }
        else if(rest == k)
        {
            count += n * time + last + 1;
        }
        else
        {
            count += n * time;
        }

        if(n > 0 && k == 0 && time != 1)
        {
            count = count - time;
        }

        if (n > 0 && k == 0 && time != 1)
        {
            count = count - time;
        }

        last += rest * time;
        time *= 10;
    }
}
