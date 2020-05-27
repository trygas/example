#include "general.h"

// 快排
// 就是把小于基准的数字放入数组左边
// 把大于基准的数字放入数组右边
// 递归排序左右两边的数组
int adjust(std::vector<int> &num, int start, int end)
{
    int i = start, j = end;
    int x = num[start];
    while (i < j){
        while(i < j && num[j] > x)
            j--;
        if (i < j){
            num[i] = num[j];
            i++;
        }

        while ( i < j && num[i] < x)
            i++;
        if (i < j){
            num[j] = num[i];
            j--;
        }
    }
    num[i] = x;
    return i;
}

void sort(std::vector<int> &num, int start, int end)
{
    if (start < end){
        int i = adjust(num, start, end);
        sort(num, start, i - 1);
        sort(num, i + 1, end);
    }
}

int main()
{
    std::vector<int> haha = {2, 3, 1, 5, 6, 10, 12, 3, 4, 7, 12, 24, 12};
    sort(haha, 0, haha.size() - 1);
    PrintVector(haha);
}