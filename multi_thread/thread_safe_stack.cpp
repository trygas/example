#include "general.h"

struct empty_stack: std::exception
{
    const char* what() const throw();
};

template <typename T>
class thread_safe_stack
{
private:
    std::stack<T> data;
    mutable std::mutex m;

public:
    thread_safe_stack(){}
    thread_safe_stack(const thread_safe_stack &other)
    {
        std::lock_guard<std::mutex> lock(other.m);
        data = other.data;
    }

    thread_safe_stack& operator = (const thread_safe_stack&) = delete;

    void push(T new_value)
    {
        lock_guard<std::mutex> lock(m);
        data.push(new_value);
    }

    std::shared_ptr<T> pop()
    {
        lock_guard<mutex> lock(m);
        if(data.empty())
            throw empty_stack();
        shared_ptr<T> const res(std::make_shared<T>(data.top()));
    }

    void pop(T &value)
    {
        lock_guard<mutex> lock(m);
        if(data.empty())
            throw empty_stack();
        value = data.pop();
        data.pop();
    }

    bool empty() const
    {
        lock_guard<mutex> lock(m);
        return data.empty();
    }
};

int main()
{
    thread_safe_stack<int> stack;
    stack.pop();
}
