#include "general.h"

int find_the_answer_to_ltuae()
{
    return (1 + 1);
}

void do_other_staff()
{
    cout << "do other staff" << endl;
}

int main()
{
    future<int> the_answer = async(find_the_answer_to_ltuae);
    do_other_staff();
    cout << "the answer is " << the_answer.get() << endl;
}