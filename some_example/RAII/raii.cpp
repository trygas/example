#include <iostream>
#include <fstream>
#include <functional>

#define SCOPEGUARD_LINENAME_CAT(name, line) name##line
#define SCOPEGUARD_LINENAME(name, line) SCOPEGUARD_LINENAME_CAT(name, line)
#define ON_SCOPE_EXIT(callback) ScopeGuard SCOPEGUARD_LINENAME(EXIT, __LINE__)(callback)

class ScopeGuard
{
public:
    explicit ScopeGuard(std::function<void()> f): handle_exit_scope_(f){};
    ~ScopeGuard()
    {
        handle_exit_scope_();
    }

private:
    std::function<void()> handle_exit_scope_;
};

int main()
{
    {
        int *a =  new int;
        ON_SCOPE_EXIT([&]{delete a;});// lambda 表达式引用捕获外部变量
    }

    {
        std::ofstream f("text.txt");
        ON_SCOPE_EXIT([&]{f.close();});
    }

    return 0;
}