#include <iostream>
#include <memory>

using namespace std;

class example
{
public:
    example(){}
};

int main()
{
    shared_ptr<example> sp0(new example);
    shared_ptr<example> sp1 = sp0;

    cout << sp0.use_count() << endl;
    sp0.reset(new example);
    cout << sp0.use_count() << endl;
    cout << sp1.use_count() << endl;
}