#include "general.h"

/*
 * 思路为采用双指针算法, 从两头走到中间,
 * 发现不一样的字符后, 要么删除左边的, 要么删除右边的
 */
int main()
{
    string s = "ececcec";

    bool isDeleted = false;
    while(s.size() > 1){
        if(s[0] == s[s.size() - 1]){
            s = s.substr(1, s.size() - 2);
            continue;
        }
        else{
            if(isDeleted)
                return false;
            else{
                if(s.size() == 2)
                    return true;
                else if(s[1] == s[s.size() - 1])
                    s = s.substr(2, s.size() - 3);
                else if(s[0] == s[s.size() - 2])
                    s = s.substr(1, s.size() - 3);

                isDeleted = true;
            }
        }
    }

    return true;
}