#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

struct TreeNode
{
    TreeNode(): left(nullptr), right(nullptr), parent(nullptr), result(0),
                is_left(0), is_right(0), is_parent(0)
    {

    }

    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    bool is_left;
    bool is_right;
    bool is_parent;
    int result;
};

void ComputeLength(TreeNode* node)
{
    if (node->parent->is_parent)
    {
        node->is_parent = 1;
        node->result = node->parent->result + 1;
    }
    else
    {
        if (node->parent->left == node)
        {
            if (node->parent->is_right)
            {
                node->is_parent = 1;
                node->result = node->parent->result + 1;
            }
            else if (node->parent->is_left)
            {
                node->is_left = 1;
                if (!node->result)
                    node->result = node->parent->result - 1;
            }
        }
        else if (node->parent->right == node)
        {
            if (node->parent->is_left)
            {
                node->is_parent = 1;
                node->result = node->parent->result + 1;
            }
            else if (node->parent->is_right)
            {
                node->is_right = 1;
                if (!node->result)
                    node->result = node->parent->result - 1;
            }
        }
    }
}

int main()
{
    string string1 = "1110001";

    if (string1[0] == 0)
        return 0;

    int size = string1.size() + 1;
    int last_size = size / 2;
    int level = -1;

    while (size)
    {
        size = size / 2;
        level++;
    }

    int string_index_start = 1;
    int string_index_end = 1;
    TreeNode* root = new TreeNode();
    deque<TreeNode*> last_node_level;
    deque<TreeNode*> node_level;
    vector<int> result;

    for (int k = last_size - 1; k < string1.size() - last_size / 2; ++k)
    {
        if (string1[k] == '1')
        {
            root->is_left = 1;
            root->result = level - 1;
            break;
        }
    }

    for (int k = string1.size() - last_size / 2; k < string1.size(); ++k)
    {
        if (string1[k] == '1')
        {
            root->is_right = 1;
            root->result = level - 1;
            break;
        }
    }

    last_node_level.push_back(root);
    result.push_back(root->result);

    for (int i = 1; i < level; ++i)
    {
        string_index_end += i * 2;

        for(int j = string_index_start; j < string_index_end; j+=2)
        {
            TreeNode* node = last_node_level.front();
            last_node_level.pop_front();

            if (node == nullptr)
            {
                node_level.push_back(nullptr);
                node_level.push_back(nullptr);
                continue;
            }

            if (string1[j] == '1')
            {
                TreeNode* left_node = new TreeNode();
                node->left = left_node;
                left_node->parent = node;
                ComputeLength(left_node);
                result.push_back(left_node->result);
                node_level.push_back(left_node);
            }
            else
                node_level.push_back(nullptr);

            if (string1[j + 1] == '1')
            {
                TreeNode* right_node = new TreeNode();
                node->right = right_node;
                right_node->parent = node;
                ComputeLength(right_node);
                result.push_back(right_node->result);
                node_level.push_back(right_node);
            }
            else
                node_level.push_back(nullptr);
        }

        last_node_level = node_level;
        node_level.clear();
        string_index_start = string_index_end;
    }

    for(int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}