#include "general.h"

/*
 * 使用快排的思想
 * 按照从大到小排序
 * 如果基准正好位于该位置则返回
 */
int findKthNum(std::vector<int> &num, int start, int end, int k){
    int x = num[start];
    int i = start;
    int j = end;

    while(i < j){
        while(i < j && num[j] < x)
            j--;
        if (i < j){
            num[i] = num[j];
            i++;
        }
        while(i < j && num[i] > x)
            i++;
        if (i < j){
            num[j] = num[i];
            j--;
        }
    }
    num[i] = x;

    if(i == k)
        return num[i];
    else{
        if (start < end){
            if (i >  k)
                return findKthNum(num, start, i - 1, k);
            else
                return findKthNum(num, i + 1, end, k);
        }
    }
}

int main()
{
    std::vector<int> haha = {1,3,4,2};
    int i = findKthNum(haha, 0, haha.size() - 1, 0);
    cout << i;
}
