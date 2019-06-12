#include <iostream>
#include <vector>

using namespace std;

int helper(vector<int> &home)
{
    int cur = 0, last = 0, be_last = 0;

    for (int i = 0; i < home.size(); ++i)
    {
        cur = max(last, be_last + home[i]);
        be_last = last;
        last = cur;
    }

    return cur;
}

int main()
{
    vector<int> home = {1, 0, 3, 5};

    if (home.empty())
    {
        cout << 0;
        return 0;
    }

    cout << helper(home);
}