#include "general.h"

/*
 * 思路是枚举中心点, 注意有一个字符和两个字符
 */

int findLongestFrom(string &s, int left, int right)
{
    int len = 0, results = 0;
    while(left - len >= 0 && right + len < s.size() && s[left - len] == s[right + len]){
        results = right - left + 2 * len + 1;
        len++;
    }

    return results;
}

int main()
{
    string s = "asddsa";
    int res_left = 0, cur_len = 0, total_len = 0;
    for(int i = 0; i < s.size(); ++i){
        cur_len = findLongestFrom(s, i, i);
        if(cur_len > total_len){
            total_len = cur_len;
            res_left = i - cur_len / 2;
        }
        cur_len = findLongestFrom(s, i, i + 1);
        if(cur_len > total_len){
            total_len = cur_len;
            res_left = i - cur_len / 2 + 1;
        }
    }

    cout << s.substr(res_left, total_len);
}