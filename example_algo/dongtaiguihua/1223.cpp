#include "general.h"

/*
 * 这个题的思路就是只要知道字符串的尾端字符和字符串的长度就可以唯一标记一个子字符串
 */
int main()
{
    string p = "zab";

    int n = p.size();
    vector<int> dp(n, 1);
    map<char, int> myMap;
    int result = 1;
    myMap[p[0]] = 1;

    for(int index = 1; index < n; ++index){
        if(p[index] == p[index - 1] + 1 || p[index] == 'a' && p[index - 1] == 'z')
            dp[index] = dp[index - 1] + 1;
        if (dp[index] > myMap[p[index]]){
            result += (dp[index] - myMap[p[index]]);
            myMap[p[index]] = dp[index];
        }
    }

    cout << result;
}
