//
// Created by liu on 18-8-19.
//

#ifndef LINTCODE_GENERAL_H
#define LINTCODE_GENERAL_H

#include <iostream>
#include <ostream>
#include <istream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <mutex>
#include <memory>
#include <stack>
#include <exception>

typedef unsigned char       ubyte;
typedef unsigned short      ushort;
typedef unsigned int        uint;
typedef unsigned long long  ullong;

#ifndef PI
#define PI 3.141592654f
#endif

#ifndef PIx2
#define PIx2 6.283185308f
#endif

#ifndef MAX_NUM_THREADS
#define MAX_NUM_THREADS 8
#endif

#ifndef MAX_LINE_LENGTH
#define MAX_LINE_LENGTH 512
#endif

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};
ListNode* CreateListNode(int value)
{
    ListNode* node = new ListNode();
    node->m_nValue = value;
    node->m_pNext = nullptr;

    return node;
}

void ConnectListNodes(ListNode* current, ListNode* next)
{
    if(current == nullptr){
        cout << "Error to connect" << endl;
        return;
    }
    current->m_pNext = next;
}

void PrintListNode(ListNode* node)
{
    if(node == nullptr)
        cout << "The node is nullptr" << endl;
    else
        cout << "The key in node is " << node->m_nValue << endl;
}

void PrintList(ListNode* head)
{
    cout << "PrintList start." << endl;
    ListNode* node = head;
    while(node != nullptr){
        cout << node->m_nValue << "\t";
        node = node->m_pNext;
    }
    cout << "\nPrintList end.\n";
}

void DestroyList(ListNode* pHead)
{
    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        pHead = pHead->m_pNext;
        delete pNode;
        pNode = pHead;
    }
}

void AddToTail(ListNode** pHead, int value)
{
    ListNode* pNew = new ListNode();
    pNew->m_nValue = value;
    pNew->m_pNext = nullptr;

    if(*pHead == nullptr)
    {
        *pHead = pNew;
    }
    else
    {
        ListNode* pNode = *pHead;
        while(pNode->m_pNext != nullptr)
            pNode = pNode->m_pNext;

        pNode->m_pNext = pNew;
    }
}

void RemoveNode(ListNode** pHead, int value)
{
    if(pHead == nullptr || *pHead == nullptr)
        return;

    ListNode* pToBeDeleted = nullptr;
    if((*pHead)->m_nValue == value)
    {
        pToBeDeleted = *pHead;
        *pHead = (*pHead)->m_pNext;
    }
    else
    {
        ListNode* pNode = *pHead;
        while(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)
            pNode = pNode->m_pNext;

        if(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value)
        {
            pToBeDeleted = pNode->m_pNext;
            pNode->m_pNext = pNode->m_pNext->m_pNext;
        }
    }

    if(pToBeDeleted != nullptr)
    {
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

BinaryTreeNode* CreateBinaryTreeNode(int value)
{
    BinaryTreeNode* node = new BinaryTreeNode();
    node->m_nValue = value;
    node->m_pLeft = nullptr;
    node->m_pRight = nullptr;
}

void ConnectTreeNodes(BinaryTreeNode* parent, BinaryTreeNode* left,
                      BinaryTreeNode* right)
{
    if(parent != nullptr){
        parent->m_pLeft = left;
        parent->m_pRight = right;
    }
}

void PrintTreeNode(const BinaryTreeNode* node)
{
    if(node != nullptr){
        printf("value of this node is: %d\n", node->m_nValue);

        if(node->m_pLeft != nullptr)
            printf("value of its left child is: %d.\n", node->m_pLeft->m_nValue);
        else
            printf("left child is nullptr.\n");

        if(node->m_pRight != nullptr)
            printf("value of its right child is: %d.\n", node->m_pRight->m_nValue);
        else
            printf("right child is nullptr.\n");
    }
    else
        printf("this node is nullptr.\n");

    printf("\n");
}

void PrintTree(const BinaryTreeNode* pRoot)
{
    PrintTreeNode(pRoot);

    if(pRoot != nullptr)
    {
        if(pRoot->m_pLeft != nullptr)
            PrintTree(pRoot->m_pLeft);

        if(pRoot->m_pRight != nullptr)
            PrintTree(pRoot->m_pRight);
    }
}

void DestroyTree(BinaryTreeNode* pRoot)
{
    if(pRoot != nullptr)
    {
        BinaryTreeNode* pLeft = pRoot->m_pLeft;
        BinaryTreeNode* pRight = pRoot->m_pRight;

        delete pRoot;
        pRoot = nullptr;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}



#endif //LINTCODE_GENERAL_H
