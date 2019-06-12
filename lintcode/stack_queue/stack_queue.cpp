#include <iostream>
#include <stack>

using namespace std;

template <class T>
class MyQueue
{
public:
    MyQueue() {}

    void push(T element)
    {
        stack1.push(element);
    }

    int pop()
    {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }

            T tmp = stack2.top();
            stack2.pop();

            return tmp;
        }
    }

    int top()
    {
        if(stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        return stack2.top();
    }

    stack<T> stack1;
    stack<T> stack2;
};

int main()
{
    MyQueue<int> queue;
    queue.push(1);
    cout << queue.pop();
    queue.push(2);
    queue.push(3);
    cout << queue.top();
}
