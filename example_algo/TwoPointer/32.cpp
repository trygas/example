#include "general.h"

/*
 * 思路就是从左到右进行遍历,
 * 如果找到了一个子串, 则缩小这个窗口找到这个窗口的最短子串
 * 然后窗口再向右移动一位, 继续寻找子串
 */
void count(string &str, map<char, int> &targetNum)
{
    for(int i = 0; i < str.size(); ++i)
        targetNum[str[i]]++;
}

int main()
{
    string source = "absdfaabab";
    string target = "adb";

    map<char, int> targetNum;
    map<char, int> sourceNum;
    count(target, targetNum);

    vector<string> res;
    int found = 0;
    int targetSize = target.size();
    int begin = -1, minLen = source.size();

    for(int i = 0, start = 0; i < source.size(); ++i){
        sourceNum[source[i]]++;
        if(sourceNum[source[i]] <= targetNum[source[i]])
            found++;

        if(found == targetSize){
            while(start < i &&
                  sourceNum[source[start]] > targetNum[source[start]]){
                sourceNum[source[start]]--;
                start++;
            }

            if(i - start < minLen){
                minLen = i - start;
                begin = start;
            }

            sourceNum[source[start]]--;
            found--;
            start++;
        }
    }

    if(begin == -1)
        cout << "";
    else
        cout << source.substr(begin, minLen + 1);
}