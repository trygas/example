#include "general.h"

// 这个代码的缺点就是只适用于单线程环境
//class Singleton
//{
//public:
//    Singleton* Instance()
//    {
//        if(instance == nullptr){
//            instance = new Singleton();
//        }
//
//        return instance;
//    }
//
//private:
//    Singleton(){}
//
//    Singleton *instance = nullptr;
//};

// 这样可以实现多线程下的单例模式, 但是非常耗时
class Singleton
{
public:
    Singleton* Instance()
    {
        {
            std::unique_lock<std::mutex> lock(mutex);
            if(instance == nullptr){
                instance = new Singleton();
            }
            return instance;
        }
    }

private:
    Singleton(){}

    Singleton *instance = nullptr;
    std::mutex mutex;
};


int main()
{

}
