#include "general.h"

/*
 * 将身高从高到低排序后依次插入即可。对于某个人[h,k]来说，插入答案的第k位。
 */
static bool comparator(vector<int> p1, vector<int> p2) {
    return (p1[0] > p2[0]) || (p1[0] == p2[0] && p1[1] < p2[1]);
}

vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    // write your code here
    sort(people.begin(), people.end(), comparator);
    vector<vector<int>> resultVector;
    for (vector<int> cur : people) {
        resultVector.insert(resultVector.begin() + cur[1], cur);
    }
    return resultVector;
}

int main()
{

}