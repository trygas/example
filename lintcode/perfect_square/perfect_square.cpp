#include <iostream>
#include <vector>

using namespace std;

int FindMinNumber(vector<int> &result, int i)
{
    int answer = 0;
    int min_result = 100000;

    for (int j = 1; j < i; ++j)
    {
        int sum = result[j] + result[i - j];

        if (sum < min_result)
        {
            min_result = sum;
        }
    }

    return min_result;
}

int helper(int number)
{
    vector<int> result(number + 1, 0);

    for (int i = 1, k = 1; i < number + 1; ++i)
    {
        if (i == k * k)
        {
            result[i] = 1;
            k++;
        }
    }

    for (int i = 2; i < number + 1; ++i)
    {
        if(i == 8)
            result[i] = 2;
        else if (!result[i])
        {
            result[i] = FindMinNumber(result, i);
        }
    }

    return result[number];
}

int main()
{
    int number = 12;

    cout << helper(number);
}