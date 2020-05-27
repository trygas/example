#include "general.h"

/*
 * 主要思路:贪心的从高到低位取数，让每一位数尽量大，
 * 如果当前数只能选择比原数位小时，后几位全都取9
 */
int main()
{
    int num = 12323;

    int dights[10], cnt = 0, pos;
    while(num != 0){
        dights[cnt++] = num % 10;
        num /= 10;
    }
    for(int i = 1; i < cnt; i++){
        if(dights[i] > dights[i - 1]){
            dights[i]--;
            pos = i;
        }
    }
    for(int i = 0; i < pos; i++){
        dights[i] = 9;
    }

    int ans = 0;
    for(int i = cnt - 1; i >= 0; i--){
        ans = ans * 10 + dights[i];
    }
    return ans;
}