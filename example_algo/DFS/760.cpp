#include "general.h"

/*
 * 主要的思路是每一层的最右边的元素是本层最后一个遍历到的元素.
 */
void Handle(TreeNode<int> *node, vector<int> &res, int layer)
{
    if(!node)
        return;
    if(layer > res.size())
        res.emplace_back(node->weight);
    if(node->left) Handle(node->left, res, layer + 1);
    if(node->right) Handle(node->right, res, layer + 1);
    res[layer - 1] = node->weight;
}

int main()
{
    vector<int> nums = {1, 2, 3, 0, 5, 0, 4};
    TreeNode<int> *root = new TreeNode<int>(nums);

    vector<int> res;
    Handle(root, res, 1);
    PrintVector(res);
}
