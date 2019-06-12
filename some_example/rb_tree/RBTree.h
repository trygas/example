//
// Created by liuguochen on 18-8-8.
//

#ifndef RB_TREE_RBTREE_H
#define RB_TREE_RBTREE_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

template <class KEY, class U>
class RBTree
{
private:
    RBTree(const RBTree& input){}
    const RBTree& operator=(const RBTree& input){}

private:
    enum COLOR{ RED, BLACK};
    class RBNode
    {
    public:
        RBNode()
        {
            right = NULL;
            left = NULL;
            parent = NULL;
        }

        COLOR RB_COLOR;
        RBNode* right;
        RBNode* left;
        RBNode* parent;
        KEY key;
        U date;
    };

public:
    RBTree();
    bool Empty();
    RBTree* find(KEY key);
    bool Insert(KEY key, U data);
    void InsertFixUp(RBNode* node);
    bool RotateLeft(RBNode* node);
    bool RotateRight(RBNode* node);
    bool Delete(KEY key);
    void DeleteFixUp(RBNode* node);
    inline RBNode* InOrderSuccessor(RBNode* node);
    void InOrderTraverse(RBNode* node);

private:
    RBNode* m_nullNode;
    RBNode* m_root;
};


#endif //RB_TREE_RBTREE_H
