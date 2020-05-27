#include "general.h"

void Handle(TreeNode<int> *node, string &midRes, vector<int> &res)
{
    if(node->left){
        midRes += to_string(node->left->weight);
        Handle(node->left, midRes, res);
        midRes.pop_back();
    }
    if(node->right){
        midRes += to_string(node->right->weight);
        Handle(node->right, midRes, res);
        midRes.pop_back();
    }
    if(!node->left && !node->right)
        res.emplace_back(std::atoi(midRes.c_str()));
}

int main()
{
    vector<int> nums = {1, 2, 3};
    TreeNode<int> *root = new TreeNode<int>(nums);

    string midRes = to_string(root->weight);
    vector<int> res;
    Handle(root, midRes, res);

    PrintVector(res);
}
