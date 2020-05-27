#include "general.h"

template <class T>
class StackWithMin
{
public:
    void push(T& value)
    {
        item.push(value);
        if(min_item.empty() || value < min_item.top())
            min_item.push(value);
        else
            min_item.push(min_item.top());
    }

    void pop()
    {
        item.pop();
        min_item.pop();
    }

private:
    stack<T> item;
    stack<T> min_item;
};
