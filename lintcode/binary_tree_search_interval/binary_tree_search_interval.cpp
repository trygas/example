//描述：给定两个值 k1 和 k2（k1 < k2）和一个二叉查找树的根节点。找到树中所有值在 k1 到 k2 范围内的节点。
// 即打印所有x (k1 <= x <= k2) 其中 x 是二叉查找树的中的节点值。返回所有升序的节点值。

//思路：从左子树到右子树开始判断

#include "general.h"

void solve(TreeNode<int>* node, int left, int right, vector<int> &result)
{
    if (!node)
        return;

    if (node->get_weight() >= left && node->get_weight() <= right)
    {
        solve(node->get_left(), left, right, result);
        result.push_back(node->get_weight());
        solve(node->get_right(), left, right, result);
    }
    else if(node->get_weight() >= right)
    {
        solve(node->get_left(), left, right, result);
    }
    else if (node->get_weight() <= left)
    {
        solve(node->get_right(), left, right, result);
    }
}

int main()
{
    vector<int> result;
    vector<int> data = {2, 1, 0};
    TreeNode<int>* root = new TreeNode<int>(data);

    solve(root, 0, 4, result);
    PrintVector(result);
}