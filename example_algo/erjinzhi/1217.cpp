#include "general.h"

int totalHammingDistance(vector<int> &nums) {
    // Write your code here
    int total = 0, n = nums.size();
    for (int j = 0; j < 32; j++) {
        int bitCount = 0;
        for (int i = 0; i < n; i++) {
            bitCount += (nums[i] >> j) & 1;
        }
        total += bitCount*(n - bitCount);
    }
    return total;
}

int main()
{

}