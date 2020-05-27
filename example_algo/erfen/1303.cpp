#include "general.h"

int main()
{
    vector<int> citations = {94,40,49,65,21,21,106,80,92,81,679,4,61,6,237,12,72,74,29,95,265,35,47,1,61,397,52,72,37,51,1,81,45,435,7,36,57,86,81,72};

    sort(citations.begin(), citations.end());
    int n = citations.size();
    int l = 0, r = n-1;
    while (l+1 < r) {
        int mid = l + (r-l) / 2;
        if (citations[mid] < n-mid) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    if (citations[r] < n-r) return n-r-1;
    return citations[l] < n-l ? n-l-1 : n-l;
}