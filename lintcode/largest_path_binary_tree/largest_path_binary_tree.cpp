#include <iostream>
#include <vector>

#include "general.h"

using namespace std;

int FindMaxSum(TreeNode<int>* node, int& last_sum)
{
    if (!node)
        return 0;

    int l = FindMaxSum(node->get_left(), last_sum);
    int r = FindMaxSum(node->get_right(), last_sum);

    last_sum = max(last_sum, max(0, l) + max(0, r) + node->get_weight());
    return max(0, max(l, r)) + node->get_weight();
}

int main()
{
    int result = INT8_MIN;
    vector<int> str1 = {1, 2, 3};

    TreeNode<int>* root = new TreeNode<int>(str1);
    FindMaxSum(root, result);
    cout << result;
}