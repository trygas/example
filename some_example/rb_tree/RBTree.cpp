//
// Created by liuguochen on 18-8-8.
//

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <sstream>

#include "RBTree.h"

template <class KEY, class U>
RBTree<KEY, U>::RBTree()
{
    this->m_nullNode = new RBNode();
    this->m_root = this->m_nullNode;
    this->m_nullNode->right = this->m_root;
    this->m_nullNode->left = this->m_root;
    this->m_nullNode->parent = this->m_root;
    this->m_nullNode->RB_COLOR = BLACK;
}

template <class KEY, class U>
bool RBTree<KEY, U>::Empty()
{
    if(m_root == m_nullNode)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 查找key
template <class KEY, class U>
RBTree<KEY, U>* RBTree<KEY, U>::find(KEY key)
{
    RBNode* index = m_root;
    while (index != m_nullNode)
    {
        if(key < index->key)// 小的在左边
        {
            index = index->left;
        }
        else if(key > index->key)// 大的在右边
        {
            index = index->right;
        }
        else
        {
            break;
        }

        return index;
    }
}

template <class KEY, class U>
bool RBTree<KEY, U>::Insert(KEY key, U data)
{
    RBNode* insert_point = m_nullNode;
    RBNode* index = m_root;

    // index为NULL
    // insert_point为NULL的父节点，我们要将新节点插入到该节点下
    while (index != m_nullNode)// 直到index为NIL节点
    {
        insert_point = index;

        if(key < index->key)
        {
            index = index->left;
        }
        else if(key > index->key)
        {
            index = index->right;
        }
        else
        {
            return false;
        }
    }

    RBNode* insert_node = new RBNode();
    insert_node->key = key;
    insert_node->date = data;
    insert_node->RB_COLOR = RED;// 新加节点为红色
    insert_node->right = m_nullNode;
    insert_node->left = m_nullNode;

    if(insert_point == m_nullNode)// 插入的是一颗空树
    {
        m_root = insert_node;
        m_root->parent = m_nullNode;
        m_nullNode->left = m_root;// m_nullNode和m_root互相为父节点
        m_nullNode->right = m_root;
        m_nullNode->parent = m_root;
    }
    else
    {
        // 判断插入节点和父节点的key值大小
        if(key < insert_point->key)
        {
            insert_point->left = insert_node;
        }
        else
        {
            insert_point->right = insert_node;
        }

        insert_node->parent = insert_point;
    }

    InsertFixUp(insert_node);// 修复红黑树性质
}

template <class KEY, class U>
void RBTree<KEY, U>::InsertFixUp(RBTree<KEY, U>::RBNode *node)
{
    // 只有父节点为红色的才需要修复红黑树性质
    while (node->parent->RB_COLOR == RED)
    {
        // 节点的父节点为祖父节点的左节点
        if(node->parent == node->parent->parent->left)
        {
            // 叔叔节点
            RBNode* uncle = node->parent->parent->right;

            // 将当前节点的父节点和叔叔节点涂黑，祖父涂红
            // 当前节点指向祖父节点，重新循环
            if(uncle->RB_COLOR == RED)// 插入情况1，叔叔节点为红色
            {
                node->parent->RB_COLOR = BLACK;
                uncle->RB_COLOR = BLACK;
                node->parent->parent->RB_COLOR = RED;
                node = node->parent->parent;
            }
            else if(uncle->RB_COLOR == BLACK)
            {
                // 插入情况2：当前节点的叔叔节点为黑色，
                // 且当前节点为父节点的右孩子
                // 插入情况2要完成if语句的部分和插入情况三的部分
                if(node == node->parent->right)
                {
                    node = node->parent;
                    RotateLeft(node);
                }
                // 插入情况3：当前节点的叔叔节点为黑色，
                // 且当前节点为父节点的右孩子
                node->parent->RB_COLOR = BLACK;
                node->parent->parent->RB_COLOR = RED;
                RotateRight(node->parent->parent);
            }
        }
        //  节点的父节点为祖父节点的右节点，旋转和上述相反
        else
        {
            RBNode* uncle = node->parent->parent->left;
            if(uncle->RB_COLOR == RED)
            {
                node->parent->RB_COLOR = BLACK;
                uncle->RB_COLOR = BLACK;
                uncle->parent->RB_COLOR = RED;
                node = node->parent->parent;
            }
            else if(uncle->RB_COLOR == BLACK)
            {
                if(node == node->parent->left)
                {
                    node = node->parent;
                    RotateRight(node);
                }

                node->parent->RB_COLOR = BLACK;
                node->parent->parent->RB_COLOR = RED;
                RotateLeft(node->parent->parent);
            }
        }


    }

    m_root->RB_COLOR = BLACK;
}

// 左旋代码实现
template <class KEY, class U>
bool RBTree<KEY, U>::RotateLeft(RBTree<KEY, U>::RBNode *node)
{
    // 不能旋转
    if(node == m_nullNode || node->right == m_nullNode)
    {
        return false;
    }

    // 当前节点及其子节点的右移操作
    RBNode* lower_right = node->right;
    lower_right->parent = node->parent;
    node->right = lower_right->left;

    if(lower_right->left != m_nullNode)
    {
        lower_right->left->parent = node;
    }
    // 旋转节点是根节点
    if(node->parent == m_nullNode)
    {
        m_root = lower_right;
        m_nullNode->left = m_root;
        m_nullNode->right = m_root;
    }
    else
    {
        // 父节点的操作
        if(node == node->parent->left)
        {
            node->parent->left = lower_right;
        }
        else
        {
            node->parent->right = lower_right;
        }
    }

    // 更新node的父节点
    node->parent = lower_right;
    lower_right->left = node;
}

template <class KEY, class U>
bool RBTree<KEY, U>::RotateRight(RBTree<KEY, U>::RBNode *node)
{
    // 不能旋转
    if(node == m_nullNode || node->left == m_nullNode)
    {
        return false;
    }

    RBNode* lower_left = node->left;
    node->left = lower_left->right;
    lower_left->parent = node->parent;

    if(lower_left->right != m_nullNode)
    {
        lower_left->right->parent = node;
    }
    if(node->parent == m_nullNode)
    {
        m_root = lower_left;
        m_nullNode->left = m_root;
        m_nullNode->right = m_root;
    }
    else
    {
        if(node == node->parent->right)
        {
            node->parent->right = lower_left;
        }
        else
        {
            node->parent->left = lower_left;
        }
    }

    node->parent = lower_left;
    lower_left->right = node;
}

template <class KEY, class U>
bool RBTree<KEY, U>::Delete(KEY key)
{
    RBNode* delete_point = find(key);

    if(delete_point == m_nullNode)
    {
        return false;
    }
    // 如果要删除节点的有两个子节点，则找到右子树的最左节点（也就是后继节点，右子树的最小节点）
    // 交换待删除节点和后继节点的数值，保持二叉树的性质
    if(delete_point->left != m_nullNode && delete_point->right != m_nullNode)
    {
        RBNode* successor = InOrderSuccessor(delete_point);
        delete_point->date = successor->date;
        delete_point->key = successor->key;
        delete_point = successor;
    }

    RBNode* delete_point_child;
    if(delete_point->right != m_nullNode)
    {
        delete_point_child = delete_point->right;
    }
    else if(delete_point->left != m_nullNode)// delete_point的左节点肯定是NULL
    {
        delete_point_child = delete_point->left;
    }
    else
    {
        delete_point_child = m_nullNode;
    }

    // 删除节点的子节点的父节点为删除节点的父节点
    delete_point_child->parent = delete_point->parent;
    // 删除根节点
    if(delete_point->parent == m_nullNode)
    {
        m_root = delete_point_child;// m_nullNode
        m_nullNode->parent = m_root;
        m_nullNode->left = m_root;
        m_nullNode->right = m_root;
    }
    else if(delete_point == delete_point->parent->right)// 只有一种可能，那就是原删除节点的右节点没有左节点
    {
        delete_point->parent->right = delete_point_child;// 删除节点的父节点的右节点为删除节点的右节点
    }
    else
    {
        delete_point->parent->left = delete_point_child;
    }

    // 只有删除节点是黑色才需要调整
    // 如果删除根节点也不需要调整
    if (delete_point->RB_COLOR == BLACK && !(delete_point_child == m_nullNode && delete_point_child->parent == m_nullNode))
    {
        DeleteFixUp(delete_point_child);
    }

    delete delete_point;
    return true;
}

template <class KEY, class U>
void RBTree<KEY, U>::DeleteFixUp(RBTree<KEY, U>::RBNode *node)
{
    // 如果当前节点为红节点，那么只需将当前节点变成黑色即可
    while(node != m_root && node->RB_COLOR == BLACK)
    {
        if(node == node->parent->left)
        {
            if(node == node->parent->left)
            {
                RBNode* brother = node->parent->right;
                if(brother->RB_COLOR == RED)// 情况1：x的兄弟是红色的
                {
                    brother->RB_COLOR = BLACK;
                    node->parent->RB_COLOR = RED;
                    RotateLeft(node->parent);
                }
                else// 情况2：x的兄弟w是黑色的
                {
                    // 且两个孩子都是黑色的
                    if(brother->left->RB_COLOR == BLACK && brother->right->RB_COLOR == BLACK)
                    {
                        brother->RB_COLOR = RED;
                        node = node->parent;
                    }
                    // 情况3：x的兄弟w是黑色的，w的右孩子是黑色（w的左孩子是红色）
                    else if (brother->right->RB_COLOR == BLACK)
                    {
                        brother->RB_COLOR = RED;
                        brother->left->RB_COLOR = BLACK;
                        RotateRight(brother);
                    }
                    else if(brother->right->RB_COLOR == BLACK && brother->right->RB_COLOR == RED)
                    // 情况4：x的兄弟w为黑色时，且w的右孩子为红色时
                    {
                        brother->RB_COLOR = node->parent->RB_COLOR;
                        node->parent->RB_COLOR = BLACK;
                        brother->right->RB_COLOR = BLACK;
                        RotateLeft(node->parent);
                        node = m_root;
                    }
                }
            }
            else
            {
                RBNode* brother = node->parent->right;
                if(brother->RB_COLOR == RED)// 情况1：x的兄弟是红色的
                {
                    brother->RB_COLOR = BLACK;
                    node->parent->RB_COLOR = RED;
                    RotateLeft(node->parent);
                }
                else// 情况2：x的兄弟w是黑色的
                {
                    // 且两个孩子都是黑色的
                    if (brother->left->RB_COLOR == BLACK && brother->right->RB_COLOR == BLACK)
                    {
                        brother->RB_COLOR = RED;
                        node = node->parent;
                    }
                        // 情况3：x的兄弟w是黑色的，w的右孩子是黑色（w的左孩子是红色）
                    else if (brother->right->RB_COLOR == BLACK)
                    {
                        brother->RB_COLOR = RED;
                        brother->left->RB_COLOR = BLACK;
                        RotateRight(brother);
                    }
                    else if (brother->right->RB_COLOR == BLACK && brother->right->RB_COLOR == RED)
                        // 情况4：x的兄弟w为黑色时，且w的右孩子为红色时
                    {
                        brother->RB_COLOR = node->parent->RB_COLOR;
                        node->parent->RB_COLOR = BLACK;
                        brother->right->RB_COLOR = BLACK;
                        RotateLeft(node->parent);
                        node = m_root;
                    }
                }
            }
        }

        m_nullNode = m_root;
        node->RB_COLOR = BLACK;
    }
}

template <class KEY, class U>
typename RBTree<KEY, U>::RBNode* RBTree<KEY, U>::InOrderSuccessor(RBTree<KEY, U>::RBNode *node)
{
//    // 空节点代表没有后继节点
//    if(node == m_nullNode)
//    {
//        return m_nullNode;
//    }
//    else if(node->right != m_nullNode)
//    {
//        RBNode* result = node->right;
//        while(result->left != m_nullNode)
//            result = result->left;
//
//        return result;
//    }
//    else// 第一个向左走的祖先
//    {
//        RBNode* result = node->parent;
//        RBNode* ch = node;
//        while(result != m_nullNode && ch == result->right)
//        {
//            ch = result;
//            result = result->parent;
//        }
//
//        return result;
//    }

    if (node == m_nullNode)       //null node has no successor
    {
        return m_nullNode;
    }
    RBNode* result = node->right;   //get node's right node
    while (result != m_nullNode)        //try to find node's right subtree's left most node
    {
        if (result->left != m_nullNode)
        {
            result = result->left;
        }
        else
        {
            break;
        }
    }                              //after while loop result==null or result's left child is null

    return result;
}
