#include "general.h"

TreeNode<int>* solve(TreeNode<int>* root, TreeNode<int>* left, TreeNode<int>* right)
{
    if (!root)
        return NULL;
    else if (root == left)
        return left;
    else if (root == right)
        return right;

    TreeNode<int>* p = solve(root->get_left(), left, right);
    TreeNode<int>* q = solve(root->get_right(), left, right);

    if (p && q)
        return root;
    return p != NULL ? p : q;
}

int main()
{
    vector<int> data = {4, 3, 7, 0, 0, 5, 6};
    TreeNode<int>* root = new TreeNode<int>(data);

    cout << solve(root, root->get_left(), root->get_right()->get_left())->get_weight();
}