#include <iostream>

using namespace std;

class A
{
public:
    int m_a;
};
class B
{
public:
    int m_b;
};
class C: public A, public B
{

};

class CSomeClass
{
public:
    void DisplaymMember();
    void DisplayAllData(const CSomeClass &mData)
    {
//        这个用法是错误的，因为DisplayMembers为普通的成员函数，故DisplayMembers成员函数中隐藏的this指针，
//        会倍编译器设置为CSomeClass* this。而mData是被const修饰的，所以实参和形参类型不一致。
//        mData.DisplaymMember();
        CSomeClass& refData = const_cast<CSomeClass&>(mData);
        refData.DisplaymMember();
    }
};

int main()
{
    C c;
    // 前两个的输出值是相同的，最后一个则会在原基础上偏移4个字节。
    // 这是因为static_cast计算了父子类指针转换的偏移量，并将之转换到正确的地址
    // （c里面有m_a,m_b，转换为B*指针后指到m_b处），而reinterpret_cast却不会做这一层转换。
    cout << &c << " " << reinterpret_cast<B*>(&c) << " " << static_cast<B*>(&c);
}
