#include "general.h"

class some_big_object
{

};
void swap(some_big_object &lhs, some_big_object &rhs);

class X
{
private:
    some_big_object some_detail;
    mutex m;
public:
    X(some_big_object const &sd): some_detail(sd){}
    friend void swap(X &lhs, X &rhs)
    {
        if(&lhs == &rhs)
            return;
        // 锁住两个或多个互斥元, 没有死锁的风险
        lock(lhs.m, rhs.m);
        //adopt_lock表示对象已经上锁, 并非尝试创建新的锁
        lock_guard<mutex> lock_a(lhs.m, std::adopt_lock);
        lock_guard<mutex> lock_b(rhs.m, std::adopt_lock);
        swap(lhs.some_detail, rhs.some_detail);
    }
};

int main()
{

}
