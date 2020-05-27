#include "general.h"

ListNode* FindListNode(ListNode *head, int index)
{
    if(head == nullptr && index == 0)
        return nullptr;

    ListNode *node = head;
    ListNode *ans = nullptr;
    for(int i = 0; i < index - 1; ++i){
        if(node->m_pNext != nullptr)
            node = node->m_pNext;
        else
            return nullptr;
    }

    ans = head;
    while(node->m_pNext != nullptr){
        node = node->m_pNext;
        ans = ans->m_pNext;
    }

    return ans;
}

int main()
{

}
