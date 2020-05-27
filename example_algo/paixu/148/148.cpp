#include "general.h"

/*
 * 主要思路就是从第1个数字开始判断0, 1, 2
 */
void sort(vector<int> &num)
{
    int left = 0, right = num.size() - 1;
    int middle = 0;

    while(middle <= right){
        if (num[middle] == 0){
            swap(num[middle], num[left]);
            left++;
            middle++;
        }
        else if(num[middle] == 1){
            middle++;
        }
        else{
            swap(num[middle], num[right]);
            right--;
        }
    }
}

int main()
{

}
