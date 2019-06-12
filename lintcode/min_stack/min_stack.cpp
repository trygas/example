#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MinStack
{
public:
    MinStack()
    {

    }

    void push(int number)
    {
        stack1.push(number);

        if(stack2.empty() || stack2.top() >= number)
            stack2.push(number);
    }

    int pop()
    {
        int tmp = stack1.top();
        stack1.pop();

        if(!stack2.empty() && stack2.top() == tmp)
            stack2.pop();

        return tmp;
    }

    int min()
    {
        if (!stack2.empty())
            return stack2.top();
    }

    stack<int> stack1;
    stack<int> stack2;
};

int main()
{
    MinStack minStack;
    minStack.push(1);
    cout << minStack.pop();
    minStack.push(2);
    minStack.push(3);
    cout << minStack.min();
    minStack.push(1);
    cout << minStack.min();
}