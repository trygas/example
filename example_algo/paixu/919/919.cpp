#include "general.h"

struct node
{
    node(int _start, int _end): start(_start), end(_end){}

    int start;
    int end;
};

/*
 * 这里的思路是将所有的开始时间和结束时间放入一个map
 * 如果连续有几个开始时间, 那么rooms就要求多了.
 */
int handle(vector<vector<int > > &nums)
{
    map<int, int> m;
    for(vector<int> num: nums){
        ++m[num[0]];
        --m[num[1]];
    }

    int rooms = 0, res = 0;
    for(auto it: m){
        res = std::max(res, rooms += it.second);
    }
    return res;
}

int main()
{
    vector<vector<int > > nums = {{0, 30}, {5, 10}, {15, 20}};
    cout << handle(nums);

    return 0;
}
