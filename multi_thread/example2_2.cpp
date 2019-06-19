#include <general.h>

class background
{
public:
    void do_length_homowork(int &i, unique_ptr<int> j)
    {
        i++;
        cout << i;
    }
};

int main()
{
    int i = 0;
    unique_ptr<int> p(new int(1));
    background back;
    thread t(&background::do_length_homowork, &back, ref(i), move(p));
    //用了move后p就没了.
    //用了ref之后传了应用到线程中.
    t.join();
    cout << i;
    cout << *p;
}