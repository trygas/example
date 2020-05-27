#include "general.h"

/*
 * 思路就是先排序, 然后通过两个指针指向两个数组,
 * 每次移动都是移动那个较小的指针.
 */
int handle(vector<int> &a, vector<int> &b){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int res = abs(a[0] - b[0]);

    for(int i = 0, j = 0; i < a.size() && j < b.size();){
        res = min(res, abs(a[i] - b[j]));
        if(a[i] < b[j])
            i++;
        else
            j++;
    }

    return res;
}

int main()
{
    vector<int> a = {1999};
    vector<int> b = {5,10,19,112,100};

    cout << handle(a, b);
}
