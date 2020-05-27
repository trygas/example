#include "general.h"

void DeleteNode(ListNode **head, ListNode *toBeDeleted)
{
    if(!head || !toBeDeleted)
        return;

    // 要删除的不是尾节点
    if(toBeDeleted->m_pNext != nullptr){
        ListNode *next = toBeDeleted->m_pNext;
        toBeDeleted->m_nValue = next->m_nValue;
        toBeDeleted->m_pNext = next->m_pNext;

        delete next;
        next = nullptr;
    }
    // 链表只有一个节点, 删除头结点
    else if (*head == toBeDeleted){
        delete toBeDeleted;
        toBeDeleted = nullptr;
        head = nullptr;
    }
    // 链表中有多个节点,删除尾节点
    else{
        ListNode *node = *head;
        while(node->m_pNext != toBeDeleted)
            node = node->m_pNext;

        node->m_pNext = nullptr;
        delete toBeDeleted;
        toBeDeleted = nullptr;
    }
}