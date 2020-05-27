#include "general.h"

int main()
{
    vector<int> nums = {3, 9, 20, 0, 0, 15, 7};
    TreeNodeInt* root = new TreeNodeInt(nums);

    queue<TreeNodeInt*> q;
    q.push(root);
    vector<int> level;
    vector<vector<int> > res;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            TreeNodeInt* node = q.front();
            q.pop();

            level.push_back(node->weight);
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }

        res.insert(res.begin(), level);
        level.clear();
    }
}