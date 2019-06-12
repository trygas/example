#include <iostream>
#include <vector>

using namespace std;

int solve(int number)
{
    vector<int> answer(number + 1, 0);

    answer[1] = 1;
    answer[2] = 2;

    for (int i = 3; i < answer.size(); ++i)
    {
        answer[i] = answer[i - 1] + answer[i - 2];
    }

    return answer[number];
}

int main()
{
    int n;
    cin >> n;

    if(n <= 0)
        return -1;

    return solve(n);
}