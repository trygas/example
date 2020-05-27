#include "general.h"

template <typename T>
class thread_safe_queue
{
private:
    // 互斥量必须是可变的, 能够在const函数和const引用中使用
    mutable mutex mut;
    queue<T> data_queue;
    condition_variable data_cond;

public:
    thread_safe_queue(){}
    thread_safe_queue(thread_safe_queue const &other)
    {
        lock_guard<mutex> lk(other.mt);
        data_queue = other.data_queue;
    }

    void push(T new_value)
    {
        lock_guard<mutex> lk(mut);
        data_queue.push(new_value);
        data_cond.notify_one();
    }

    void wait_and_pop(T& value)
    {
        unique_lock<mutex> lk(mut);
        // 在这里[]中加入this, 可以从lambda中访问类成员
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = data_queue.front();
        data_queue.pop();
    }

    std::shared_ptr<T> wait_and_pop()
    {
        unique_lock<mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        shared_ptr<T> res(make_shared<T>(data_queue.front()));
        data_queue.pop();
        return res;
    }

    bool try_pop(T &value)
    {
        lock_guard<mutex> lk(mut);
        if(data_queue.empty())
            return false;
        value = data_queue.front;
        data_queue.pop();
        return true;
    }

    shared_ptr<T> try_pop()
    {
        lock_guard<mutex> lk(mut);
        if(data_queue.empty())
            return shared_ptr<T>();
        shared_ptr<T> res(make_shared<T>(data_queue.front()));
        data_queue.pop();
        return res;
    }

    bool empty() const
    {
        lock_guard<mutex> lk(mut);
        return data_queue.empty();
    }
};

int main()
{

}