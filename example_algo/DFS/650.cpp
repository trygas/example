#include "general.h"

void dfs(TreeNode<int> **node, vector<int> &midRes)
{
    if(!(*node)->left && !(*node)->right){
        midRes.emplace_back((*node)->weight);
        if((*node)->parent && (*node)->parent->left == (*node))
            (*node)->parent->left = nullptr;
        else if((*node)->parent && (*node)->parent->right == (*node))
            (*node)->parent->right = nullptr;
        (*node) = nullptr;
        return;
    }
    if((*node)->left)
        dfs((&(*node)->left), midRes);
    if((*node)->right)
        dfs((&(*node)->right), midRes);
}

void Handle(TreeNode<int> *node, vector<vector<int> > &res)
{
    while(node != nullptr){
        vector<int> midRes;
        dfs(&node, midRes);
        res.emplace_back(midRes);
    }
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 0, 0};
    TreeNode<int> *root = new TreeNode<int>(nums);

    vector<vector<int> > res;
    Handle(root, res);
    PrintVectorVector(res);
}
