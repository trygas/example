#include "general.h"

/*
 * 思路是先遍历字符串, 如果某一个字符的数量小于k,
 * 那么最终的答案中一定不会包含这个字符, 因此答案只有可能在这个字符的左右两侧的字符串
 * 之后对于左右两边的串进行递归处理即可.
 */
int longestSubstring(string s, int k) {
    if(s.size() == 0) return 0;
    if(k <= 1) return s.size();
    map<char,int> cnt;
    for(int i = 0; i < s.size(); ++i) {
        cnt[s[i]]++;
    }
    bool allMoreK = true;
    for(auto a : cnt) {
        if(a.second < k) {
            allMoreK = false;
        }
    }
    if(allMoreK) return s.size();

    int longest = 0;
    int start = 0;
    while(start < s.size()) {
        while(start < s.size() && cnt[s[start]] < k) {
            start++;
        }
        int end = start;
        for(;end <= s.size(); ++end) {
            if((end == s.size() && start < s.size()) || (end < s.size() && cnt[s[end]] < k)) {
                longest = max(longest,longestSubstring(s.substr(start,end-start),k));
                break;
            }
        }
        start = end+1;
    }
    return longest;
}

int main()
{
}