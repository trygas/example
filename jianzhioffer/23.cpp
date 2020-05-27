#include "general.h"

ListNode* MeetingNode(ListNode* head)
{
    if(head == nullptr)
        return nullptr;

    ListNode* slow = head->m_pNext;
    if(slow == nullptr)
        return nullptr;
    ListNode* fast = slow->m_pNext;
    while(fast != nullptr && slow != nullptr){
        if(fast == slow)
            return fast;
        slow = slow->m_pNext;
        fast = fast->m_pNext;
        if(fast != nullptr)
            fast = fast->m_pNext;
    }

    return nullptr;
}

ListNode* EntryNodeOfLoop(ListNode* head)
{
    ListNode* meetingNode = MeetingNode(head);
    if(meetingNode == nullptr)
        return nullptr;

    int nodesInLoop = 1;
    ListNode* node = meetingNode;
    while(node->m_pNext !=  meetingNode){
        node = node->m_pNext;
        ++nodesInLoop;
    }

    node = head;
    for(int i = 0; i < nodesInLoop; ++i)
        node = node->m_pNext;
    ListNode* node2 = head;
    while(node != node2){
        node = node->m_pNext;
        node2 = node2->m_pNext;
    }

    return node;
}