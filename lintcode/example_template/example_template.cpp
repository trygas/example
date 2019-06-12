#include <iostream>

using namespace std;

template<class T1, class T2>
class SameType
{
public:
    enum {ret = false};
};

// 模板特化，当两个类型相等时，选择特化版本，否则选择非特化版本
template <class T>
class SameType<T, T>
{
public:
    enum {ret = true};
};

template <int N>
class aTMP
{
public:
    enum {ret = N * aTMP<N-1>::ret};
};

// 特例化
// 如果没有这一段，那么就编译不过，上面的ret依赖于aTMP<N-1>，但不知道什么时候停止
// 有了一段代码，就能判断是在这里停止了
template <>
class aTMP<0>
{
public:
    enum {ret = 1};
};

template <class T>
class bTMP
{
public:
    // 类型计算统一用using关键字定义类型别名
    using reType = const T;
};

void f()
{
    cout << "global f()\n";
}

template <class T>
class Base
{
public:
    template <int N = 99>
    void f()
    {
        cout << "member f():" << N << endl;
    }
};

template <class T>
class Derived:public Base<T>
{
public:
    typename T::reType m;// typename不能省略
    Derived(typename T::reType a): m(a){}

    void df1(){f();} // 调用全局f()
    void df2(){this->f();} // 基类f<99>()
    void df3(){Base<T>::template f<22>();} // 强制基类f<22>()，不能省略template，这里指明嵌套类型或函数为模板
    void df4(){::f();} // 强制全局f()
};

// 对Value的计算发生在编译期
template <int X, int Y>
struct Caculate
{
    // 多返回值用的不多，因为如果我们只想要其中一个结果，但是实际上是所有结果都被一起计算了
    // 还有一个重要原因是多个返回值的名字都不一样，这会对编译期的函数组合能力造成障碍
    enum
    {
        Sum = X + Y,
        Dec = X - Y,
        Mul = X * Y,
        Div = X / Y
    };
};

int main()
{
    cout << SameType<unsigned int, unsigned int>::ret << endl;// 输出1，同一个模板相同
    cout << aTMP<5>::ret << endl;

    Derived<bTMP<int> > b(5);
    b.df1();
    b.df2();
    b.df3();
    b.df4();

    cout << Caculate<3, 4>::Sum << endl;
}