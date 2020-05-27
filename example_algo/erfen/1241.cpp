#include "general.h"

int main()
{
    vector<Interval> intervals = {Interval(3, 4),
                                  Interval(2, 3),
                                  Interval(1, 2)};

    int n = intervals.size();
    map<int, int> m;
    vector<int> vec(n, 0), res(n, -1);
    for(int i = 0; i < n; ++i){
        int tmp = intervals[i].start;
        vec[i] = intervals[i].start;
        m[tmp] = i;
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < n; ++i){
        int end = intervals[i].end;
        auto it = lower_bound(vec.begin(), vec.end(), end);
        if(it != vec.end())
            res[i] = m[*it];
    }

    PrintVector(res);
}