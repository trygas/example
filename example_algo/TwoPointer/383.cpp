#include "general.h"

int main()
{
    vector<int> heights = {1, 3, 2, 2};

    int left = 0, right = heights.size() - 1;
    int max = -1;
    while(left < right){
        max = std::max(max, (right - left) * std::min(heights[left], heights[right]));
        if(heights[left] <= heights[right])
            left++;
        else
            right--;
    }

    cout << max;
}
