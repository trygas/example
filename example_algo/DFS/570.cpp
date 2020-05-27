#include "general.h"

int getNumber(string &str, int start, int len)
{
    return atoi(str.substr(start, len).c_str());
}

int Handle(string &str, int n, vector<bool> &visited, int index)
{
    // 当所有的字符串都使用完了进行判断
    if (index == str.size()){
        vector<int> result;
        for(int i = 1; i <= n; ++i){
            if(!visited[i])
                result.emplace_back(i);
        }
        if (result.size() == 1)
            return result[0];
        else
            return -1;
    }
    if (str[index] == '0')
        return -1;

    for(int i = 1; i < 3; ++i){
        int num = getNumber(str, index, i);
        if (num >= 1 && num <= n && !visited[num]){
            visited[num] = true;
            int target = Handle(str, n, visited, index + i);
            if (target != -1)
                return target;
            // 为了切换下一个数据
            visited[num] = false;
        }
    }

    return -1;
}

int main()
{
    int n = 11;
    string str = "111098765432";

    vector<bool> visited(n + 1, false);
    cout << Handle(str, n, visited, 0);
}
