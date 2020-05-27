#include "general.h"

int nthSuperUglyNumber(int n, vector<int> &primes)
{
    priority_queue<int, vector<int>, greater<int> > heap;
    set<int> vis;
    heap.push(1);

    for(int i = 1; i < n; ++i){
        int t = heap.top();
        heap.pop();
        vis.insert(t);
        for(int j: primes)
            heap.push(t * j);
        while(vis.find(heap.top()) != vis.end())
            heap.pop();
    }

    return heap.top();
}

int main()
{

}