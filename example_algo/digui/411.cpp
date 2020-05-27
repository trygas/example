#include "general.h"

int toInt(string &str)
{
    int res = 0;
    int n = str.size();
    for(int i = 0; i < n; ++i){
        if(str[i] == '1')
            res += pow(2, n - i - 1);
    }

    return res;
}

vector<int> grayCode(int n)
{
    if(n == 0)
        return {0};
    vector<string> res;
    res.push_back("0");
    res.push_back("1");

    for(int i = 2; i <= n; ++i){
        for(int j = res.size() - 1; j >= 0; --j){
            while(res[j].size() < i - 1)
                res[j] = "0" + res[j];
            res.push_back("1" + res[j]);
        }
    }

    vector<int> intRes;
    for(int i = 0; i < res.size(); ++i)
        intRes.push_back(toInt(res[i]));

    return intRes;
}

int main()
{
    PrintVector(grayCode(4));
}

