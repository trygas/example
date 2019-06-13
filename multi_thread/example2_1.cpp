#include <thread>
#include <iostream>

class background
{
public:
    void operator()()
    {
        std::cout << "haha";
        std::cout << num;
        num++;
        std::cout << num;
        num++;

    }
    int num;
};

class thread_guard
{
public:
    std::thread& t;
    explicit thread_guard(std::thread& _t):t(_t){}
    ~thread_guard()
    {
        if(t.joinable())
            t.join();
    }

    thread_guard(thread_guard const&)= delete;
    thread_guard& operator=(thread_guard const&)= delete;
};

int main()
{
    background f;
    f.num=1;
    std::thread mythread(f);
    thread_guard guard(mythread);
    return 0;
}