#include "general.h"

static bool cmp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

/*
 * 思路就是将第二个数字按大小排序, 然后确定最长数对链.
 */
int main()
{
    vector<vector<int > > pairs = {{1,2}, {2,3}, {3,4}};
    sort(pairs.begin(), pairs.end(), cmp);
    int res = 0, cur = INT32_MIN;

    for(int i = 0; i < pairs.size(); ++i){
        if (pairs[i][0] > cur){
            cur = pairs[i][1];
            res += 1;
        }
    }

    cout << res;
}
