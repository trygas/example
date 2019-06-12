#include <iostream>
#include <time.h>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;
bool ready = false;
int cargo = 0;// producers和consumers的共同参数

void delay_ms(int ms)
{
    clock_t start = clock();
    while (clock() - start < ms);
}

void thread_proc()
{
    cout << "thread id = " << this_thread::get_id() << std::endl;
}

class functor
{
public:
    void operator()(int a, int b)
    {
        cout << a << "+" << b << "=" << a + b << endl;
    }
};

class C
{
    int data;

public:
    C(int _data): data(_data){}
    void member_func()
    {
        cout << "this->data = " << this->data << endl;
    }
};

void do_print_id(int id)
{
    unique_lock<mutex> lock(mtx);
    while (!ready)
        cv.wait(lock);
    cout << "thread " << id << endl;
}

void go()
{
    unique_lock<mutex> lock(mtx);
    ready = true;
    cv.notify_all();// 唤醒所有线程
}

void consumer()
{
    unique_lock<mutex> lock(mtx);
    while (cargo == 0)
        cv.wait(lock);

    cout << cargo << endl;
    cargo = 0;
}

void producer(int id)
{
    unique_lock<mutex> lock(mtx);
    cargo = id;
    cv.notify_one();
}

int main()
{
    // 创造出joinable对象必须join或detach
    thread td1(thread_proc);// 创建thread对象即创建了一个新的线程并执行
    td1.join();// 等待线程执行结束

    // thread的执行体并不要求必须是普通函数，任何可调用的对象都是可以的。
    thread td2([](int a, int b){
        cout << a << "+" << b << "=" << a + b << endl;
    }, 1, 2);
    td2.join();

    thread td3(functor(), 3, 4);
    td3.join();

    C obj(10);
    thread td4(bind(&C::member_func, &obj));
    // join后就不是joinable()了。
    cout << "td4.joinable() = " << boolalpha << td4.joinable() << endl;
    td4.join();

    thread threads[10];

    for (int i = 0; i < 10; ++i)
    {
        threads[i] = thread(do_print_id, i);
    }
    cout << "10 threads ready to race..." << endl;
    go();

    for(auto &th : threads)
        th.join();

    thread consumers[10], producers[10];

    for (int j = 0; j < 10; ++j)
    {
        consumers[j] = thread(consumer);
        producers[j] = thread(producer, j + 1);
    }

    for (int k = 0; k < 10; ++k)
    {
        producers[k].join();
        consumers[k].join();
    }

    return 0;
}
