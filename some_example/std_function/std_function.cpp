#include <functional>
#include <iostream>

int Testfunction(int a, int b)
{
    return a * b;
}

auto lambda = [](int a, int b){return a * b;};

class Functor
{
public:
    int operator()(int a, int b)
    {
        return a * b;
    }
};

class TestClass
{
public:
    int ClassMember(int a, int b)
    {
        return a * b;
    }
    static int StaticMember(int a, int b)
    {
        return a * b;
    }
};

int main()
{
    std::function<int(int, int)> function;
    function = Testfunction;
    std::cout << function(10, 10) << std::endl;

    function = lambda;
    std::cout << function(20, 20) << std::endl;

    Functor test_functor;
    function = test_functor;
    std::cout << function(30, 30) << std::endl;

    TestClass testClass;
    function = std::bind(&TestClass::ClassMember, testClass, std::placeholders::_1, std::placeholders::_2);
    std::cout << function(40, 40) << std::endl;

    function = TestClass::StaticMember;
    std::cout << function(50, 50) << std::endl;
}