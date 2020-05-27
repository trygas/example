#include "general.h"

void helper(ListNode<int> *head, vector<int> &res)
{
    if(head == nullptr)
        return;
    else
        helper(head->get_next(), res);

    res.push_back(head->get_val());
}

vector<int> reverseStore(ListNode<int> * head)
{
    vector<int> res;
    helper(head, res);
    return res;
}
