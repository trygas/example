#include <iostream>
#include <vector>
#include <map>
#include <queue>

#include "general.h"

using namespace std;

void solve(TreeNode<int>* root, vector<vector<int> > &result)
{
    map<int, vector<int> > map1;
    queue<pair<int, TreeNode<int>* > > queue1;
    queue1.push({0, root});

    while (!queue1.empty())
    {
        auto a = queue1.front();
        queue1.pop();

        map1[a.first].push_back(a.second->get_weight());
        if(a.second->get_left()) queue1.push({a.first - 1, a.second->get_left()});
        if(a.second->get_right()) queue1.push({a.first + 1, a.second->get_right()});
    }

    for(auto a : map1)
    {
        result.push_back(a.second);
    }
}

int main()
{
    TreeNode<int> *root = new TreeNode<int>({3, 9, 20, 0, 0, 15, 7});
    vector<vector<int> > result;

    solve(root, result);

    PrintVectorVector(result);
}