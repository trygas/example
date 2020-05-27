#include "general.h"

void ConvertNode(BinaryTreeNode* node, BinaryTreeNode **lastNodeInList)
{
    if(!node)
        return;

    BinaryTreeNode* current = node;
    if(current->m_pLeft)
        ConvertNode(node->m_pLeft, lastNodeInList);

    current->m_pLeft = *lastNodeInList;
    if(*lastNodeInList)
        (*lastNodeInList)->m_pRight = current;

    *lastNodeInList = current;
    if(current->m_pRight)
        ConvertNode(current->m_pRight, lastNodeInList);
}

BinaryTreeNode* Convert(BinaryTreeNode* node)
{
    BinaryTreeNode* lastNodeInList = nullptr;
    ConvertNode(node, &lastNodeInList);

    BinaryTreeNode* headOfList = lastNodeInList;
    while(headOfList != nullptr && headOfList->m_pLeft)
        headOfList = headOfList->m_pLeft;

    return headOfList;
}
