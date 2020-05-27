#include "general.h"

bool Handle(TreeNodeInt* node)
{
    TreeNodeInt* left = node->left;
    TreeNodeInt* right = node->right;

    if(left && right){
        bool ans1 = Handle(left);
        bool ans2 = Handle(right);
        if(!ans1 || !ans2)
            return false;
    }
    else if(!left && !right){}
    else
        return false;

    return true;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 0, 0, 0};
    TreeNodeInt* root = new TreeNodeInt(nums);

    return Handle(root);
}