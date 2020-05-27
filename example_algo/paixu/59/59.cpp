#include "general.h"

/*
 * 这个题目是最接近的三个数之和, 主要思路就是四数之和, 只不过要变一下
 */
vector<int> findVector(std::vector<int> &num, int k){
    int sum = INT32_MAX;
    vector<int> midRes;
    for(int i = 0; i < num.size() - 1; ++i){
        while (i != 0 &&  num[i] == num[i - 1])
            i++;

        int left = i + 1;
        int right = num.size() - 1;
        int temp = k - num[i];

        while(left < right){
            while(left < right && left != i + 1 && num[left] == num[left - 1])
                left++;
            while(left < right && right != num.size() - 1 && num[right + 1] == num[right])
                right--;

            int midSum = abs(temp - num[left] - num[right]);
            if (sum > midSum && left < right){
                sum = midSum;
                midRes.clear();
                midRes.emplace_back(num[i]);
                midRes.emplace_back(num[left]);
                midRes.emplace_back(num[right]);
            }
            if (num[left] + num[right] > temp)
                right--;
            else
                left++;
        }
    }

    return midRes;
}

int main()
{
    vector<int> num = {2,7,11,15};
    int target = 3;
    sort(num.begin(), num.end());

    vector<int> result;
    PrintVector(findVector(num, target));
}