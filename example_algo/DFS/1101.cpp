#include "general.h"

vector<pair<int, int> > edge;

void dfs(TreeNodeInt *now, int depth, int idx)
{
    if(now == nullptr)
        return;

    if(edge.size() <= depth)
        edge.push_back({idx, idx});
    else{
        edge[depth].first = std::min(idx, edge[depth].first);
        edge[depth].second = std::max(idx, edge[depth].second);
    }

    dfs(now->left, depth + 1, idx * 2);
    dfs(now->right, depth + 1, idx * 2 + 1);
}

int main()
{
    vector<int> nums = {1, 3, 2, 5, 3, 0, 9};
    TreeNodeInt* root = new TreeNodeInt(nums);

    dfs(root, 0, 0);
    int ans = 0;
    for(auto &i: edge)
        ans = std::max(i.second - i.first + 1, ans);

    cout << ans;
}