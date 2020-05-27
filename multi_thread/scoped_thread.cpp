#include "general.h"

double func()
{
    cout << "haha";
}

class scoped_thread
{
public:
    thread t;
    explicit scoped_thread(thread _t):t(move(_t))
    {
        if(!t.joinable())
            throw logic_error("no error");
    }
    ~scoped_thread()
    {
        t.join();
    }

    scoped_thread(scoped_thread const&)= delete;
    scoped_thread& operator=(scoped_thread const&)=delete;
};

int main()
{
    // 必须显式的调用move
    scoped_thread t(move(thread(func)));
    return 0;
}