#include "general.h"

int main()
{
    vector<int> numbers = {1, 2, 3, 4, 5};
    priority_queue<int, vector<int>, greater<int> > Q;
    for(int i: numbers)
        Q.push(i);

    int ans = 0;
    while (Q.size() > 1){
        int a = Q.top();
        Q.pop();
        int b = Q.top();
        Q.pop();
        ans += a + b;
        Q.push(a + b);
    }

    return ans;
}