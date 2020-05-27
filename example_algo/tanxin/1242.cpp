#include "general.h"

/*
 * 首先对这个数组的start进行排序,
 * 设置ref为最小的start
 * 再遍历后面的interval, 如果start >= ref, 则将ref更新为当前区间的end
 * 否则将ref 更新为min(ref, end), 同时答案加一
 */
int main()
{
    vector<Interval> intervals;
    intervals.push_back(Interval(1, 2));
    intervals.push_back(Interval(2, 3));
    intervals.push_back(Interval(3, 4));
    intervals.push_back(Interval(1, 3));

    sort(intervals.begin(), intervals.end(),
         [](Interval& a, Interval& b){
            return a.start < b.start;
    });

    int count = 1;
    int end = intervals[0].end;
    for(int i = 1; i < intervals.size(); ++i){
        if(intervals[i].start >= end){
            count++;
            end = intervals[i].end;
        }
        else{
            end = std::min(end, intervals[i].end);
        }
    }

    cout << intervals.size() - count;
}