#include "general.h"

/*
 * 主要思路是记录每个字母上一次出现的位置
 * 再设定一个左边界, 到当前遍历到的位置之间的字符串为不含重复字符的子串
 * 若新碰到的字符的上一次的位置在左边界右边,
 * 则需要向右边移动左边界
 */
int main()
{
    string s = "z";

    int ans = 0, left = 0, len = s.length();
    int last[255];
    memset(last, -1, sizeof last);

    for (int i = 0; i < len; i++) {
        // 上次出现位置在当前记录边界之后，即该子串中出现了重复字符，需调整left使得子串合法
        if (last[s[i]] >= left) left = last[s[i]] + 1;
        last[s[i]] = i;
        ans = max(ans, i - left + 1);
    }
    return ans;
}