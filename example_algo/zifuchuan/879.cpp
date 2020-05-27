#include "general.h"

int main()
{
    int n = 8;

    vector<string> res;
    for(int i = 1; i <= n; ++i){
        res.push_back(to_string(i));
    }

    while(res.size() != 1){
        for (int i = 0; i < res.size() / 2; ++i)
        {
            string str = "(" + res[i] + "," + res[res.size() - i - 1] + ")";
            res[i] = str;
        }
        res.resize(res.size() / 2);
    }

    PrintVector(res);
}