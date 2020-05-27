#include "general.h"

void sort(std::vector<int> &num, int start, int end)
{
    int i = start, j = end;
    int x = num[start];

    while (i < j){
        while( i < j && num[j] > x)
            j--;
        if (i < j){
            num[i] = num[j];
            i++;
        }

        while (i < j && num[i] < x)
            i++;
        if (i < j){
            num[j] = num[i];
            j--;
        }
    }

    num[i] = x;

    if (start < end){
        sort(num, start, i - 1);
        sort(num, i + 1, end);
    }
}

/*
 * 主要思想就是先排序
 * 排序后, 固定两个数字i,j, 后面的两个数字left,right进行移动
 * i,j,left,right的思想都是使用完的数字抛弃不要
 */
void findVector(std::vector<int> &num, vector<vector<int> > &result, int k)
{
    for(int i = 0; i < num.size() - 3; i++){
        // 用过的i不能再用了
        while(i != 0 && num[i - 1] == num[i])
            i++;
        for(int j = i + 1; j < num.size() - 2; j++){
            // 同理用过的j不能再用了
            while (j != i + 1 && num[j] == num[j - 1])
                j = j + 1;

            int temp = k - num[i] - num[j];
            int left = j + 1, right = num.size() - 1;

            while(left < right){
                // 用过的值i,j不能用
                while(left < right && left != j + 1 && num[left] == num[left - 1])
                    left++;
                while(left < right && right != num.size() - 1 && num[right] == num[right + 1])
                    right--;

                if(left < right && num[left] + num[right] == temp){
                    vector<int> oneRes = {num[i], num[j], num[left], num[right]};
                    result.emplace_back(oneRes);
                    left++;
                    right--;
                    continue;
                }
                // 判断离哪边更近一点.
                if(num[left] + num[right] < temp)
                    left++;
                else
                    right--;
            }
        }
    }
}

int main()
{
    vector<int> num = {1,0,-1,-1,-1,-1,0,1,1,1,2};
    int target = 2;
    sort(num, 0, num.size() - 1);

    vector<vector<int> > result;
    findVector(num, result, target);

    PrintVectorVector(result);
}