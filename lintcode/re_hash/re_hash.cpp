#include <iostream>
#include <vector>

#include "general.h"

using namespace std;

int main()
{
    ListNode<int>* a = new ListNode<int>(42);
    ListNode<int>* b = new ListNode<int>(32);
    ListNode<int>* c = new ListNode<int>(-7);
    vector<ListNode<int>*> hash_table;
    hash_table.resize(5, nullptr);

    a->set_next(b);
    hash_table[2] = a;
    hash_table[3] = c;

    PrintVectorList(hash_table);
    cout << endl;

    int new_size = hash_table.size() * 2;

    vector<ListNode<int>*> res(new_size, nullptr);

    for (int i = 0; i < hash_table.size(); ++i)
    {
        ListNode<int>* node = hash_table[i];

        while (node != nullptr)
        {
            ListNode<int> *temp = node;
            node = node->get_next();

            int index = (temp->get_val() % new_size + new_size) % new_size;

            if(res[index] == nullptr)
            {
                res[index] = temp;
                temp->set_next(nullptr);
            }
            else
            {
                ListNode<int> *p = res[index];
                while (p->get_next() != nullptr) p = p->get_next();
                p->set_next(temp);
                temp->set_next(nullptr);
            }
        }
    }

    PrintVectorList(res);
}