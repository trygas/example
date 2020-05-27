#include "general.h"

string removeKdigits(string num, int k)
{
    // write your code here.
    for(int i = 0; i < k; ++i){
        for(int j = 0; j < num.size() - 1; ++j){
            if(num[j] > num[j + 1])
            {
                num = num.substr(0, j) + num.substr(j + 1);
                break;
            }
            if(j == num.size() - 2)
                num = num.substr(0, j);
        }
    }

    while(num.size() > 1 && num[0] == '0')
        num = num.substr(1);
    return num;
}

int main()
{
    cout << removeKdigits("637824056", 8);
}
