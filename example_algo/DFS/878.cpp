#include "general.h"

/*
 * 思路就是进行三次DFS, 分别把左边界, 叶子, 右边界放到答案序列
 */
void dfsBottom(TreeNode<int> *rt, vector<int> &res)
{
    if(!rt)
        return;
    if(!rt->left && !rt->right){
        res.emplace_back(rt->weight);
        return;
    }
    dfsBottom(rt->left, res);
    dfsBottom(rt->right, res);
}

void dfsLeft(TreeNode<int> *rt, vector<int> &res)
{
    if(!rt || (!rt->left && !rt->right))
        return;
    res.emplace_back(rt->weight);
    if(!rt->left)
        dfsLeft(rt->left, res);
    else
        dfsLeft(rt->right, res);
}

void dfsRight(TreeNode<int> *rt, vector<int> &res)
{
    if(!rt || (!rt->left && !rt->right))
        return;
    if(!rt->right)
        dfsRight(rt->right, res);
    else
        dfsRight(rt->left, res);
    res.emplace_back(rt->weight);
}

int main()
{
    vector<int> nums = {1, 0, 2, 0, 0, 3, 4};
    TreeNode<int> *root = new TreeNode<int>(nums);

    if(root == NULL)
        return 0;
    vector<int> res;
    res.emplace_back(root->weight);
    if(!root->left && !root->right)
        return 0;
    dfsLeft(root->left, res);
    dfsBottom(root, res);
    dfsRight(root->right, res);
    PrintVector(res);
}
