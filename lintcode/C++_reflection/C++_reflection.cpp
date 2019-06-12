#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define REGISTER(className) \
    className* objectCreate##className() \
{ \
    return new className(); \
}\
RegisterAction g_creatorRegister##className(#className, (PTRCreateObject)objectCreator##className)

typedef void* (*PTRCreateObject)(void);

class ClassFactory
{
private:
    map<string, PTRCreateObject > m_classMap;
    ClassFactory(){}

public:
    static ClassFactory& getInstance()
    {
        static ClassFactory factory;
        return factory;
    }

    void* getClassByName(string className)
    {
        map<string, PTRCreateObject >::const_iterator iter;
        iter = m_classMap.find(className);

        if(iter == m_classMap.end())
            return nullptr;
        else
            return iter->second();
    }

    void registClass(string name, PTRCreateObject method)
    {
        m_classMap.insert(pair<string, PTRCreateObject>(name, method));
    }
};

class TestClassA
{
public:
    void m_print()
    {
        cout << "TestA" << endl;
    }
};

class RegisterAction
{
public:
    RegisterAction(string className, PTRCreateObject ptrCreateFn)
    {
        ClassFactory::getInstance().registClass(className, ptrCreateFn);
    }
};

int main()
{
    TestClassA* ptrObj = (TestClassA*)ClassFactory::getInstance().getClassByName("TestClassA");
    ptrObj->m_print();
}