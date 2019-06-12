#include <iostream>
#include <vector>
#include <algorithm>

#include "general.h"

using namespace std;

void random_distribution(vector<int> &friend_toy, int toy_number)
{
    for (int i = 0; i < friend_toy.size() - 1; ++i)
    {
        int random_number = RandomNumber(0, toy_number);
        friend_toy[i] = random_number;
        toy_number -= random_number;
    }

    friend_toy[friend_toy.size() - 1] = toy_number;
}

void solve(vector<int> &friend_toy, int sum)
{
    int average_number = sum / friend_toy.size();
    sort(friend_toy.begin(), friend_toy.end(), [](int a, int b){return a > b;});

    for (int i = 0; i < friend_toy.size() - 1; ++i)
    {
        friend_toy[i + 1] += friend_toy[i] - average_number;
        friend_toy[i] = average_number;
    }

    PrintVector(friend_toy);
}

int main()
{
    int friend_number = 10;
    int every_friend_toy = 10;

    vector<int> friend_toy(friend_number, 0);

    random_distribution(friend_toy, friend_number * every_friend_toy);
    solve(friend_toy, friend_number * every_friend_toy);
}