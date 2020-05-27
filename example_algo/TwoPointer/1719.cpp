#include "general.h"

int threeSumMulti(vector<int> &A, int target)
{
    map<int, long> counter;
    for(int a: A)
        counter[a]++;

    long res = 0;

    for(auto it: counter){
        for(auto it2: counter){
            int i = it.first, j = it2.first, k = target - i - j;
            if (!counter.count(k))
                continue;
            if (i == j && j == k)
                res += counter[i] * (counter[i] - 1) * (counter[i] - 2) / 6;
            else if (i == j && j != k)
                res += counter[i] * (counter[i] - 1) / 2 * (counter[k]);
            // 规定元素之间的大小关系是为了防止重复计算
            else if (i < j && j < k)
                res += counter[i] * counter[j] * counter[k];
        }
    }

    return res % int(1e9 + 7);
}
