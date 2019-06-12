#include <iostream>
#include <vector>

using namespace std;

int helper(vector<vector<int> > &cost)
{
    if (cost.empty())
        return 0;

    vector<vector<int> > sum(cost.size(), vector<int>(3, 0));

    sum[0][0] = cost[0][0];
    sum[0][1] = cost[0][1];
    sum[0][2] = cost[0][2];

    for (int i = 1; i < cost.size(); ++i)
    {
        sum[i][0] = min(sum[i - 1][1], sum[i - 1][2]) + cost[i][0];
        sum[i][1] = min(sum[i - 1][0], sum[i - 1][2]) + cost[i][1];
        sum[i][2] = min(sum[i - 1][0], sum[i - 1][1]) + cost[i][2];
    }

    return min(sum[cost.size() - 1][0], min(sum[cost.size() - 1][1], sum[cost.size() - 1][2]));
}

int main()
{
    vector<vector<int> > cost = {{14, 2, 11}, {11, 14, 5}, {14, 3, 10}};

    cout << helper(cost);
}