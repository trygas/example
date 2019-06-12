//题目：描述
//    设计一个算法，找出只含素因子2，3，5 的第 n 小的数。
//
//符合条件的数如：1, 2, 3, 4, 5, 6, 8, 9, 10, 12...

// 思路：调用一个优先队列

#include "general.h"

int solve(int number)
{
    priority_queue<long, vector<long>, greater<long> > queue1;
    queue1.push(1);

    if (number == 1)
        return 1;

    for (int i = 1; i < number; ++i)
    {
        long tmp = queue1.top();

        queue1.push(tmp * 2);
        queue1.push(tmp * 3);
        queue1.push(tmp * 5);

        while (queue1.top() == tmp)
            queue1.pop();
    }

    return queue1.top();
}

int main()
{
    int number = 7;
    cout << solve(number);
}