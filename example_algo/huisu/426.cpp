#include "general.h"

void Handle(vector<string> &res, string midRes,
            string &leftStr, int n)
{
    if(n == 0){
        int num = atoi(leftStr.c_str());
        if((leftStr.size() <= 3 && num <= 255) && (num > 0 && leftStr[0] != '0') || (num == 0 && leftStr.size() == 1))
            res.push_back(midRes + leftStr);
        return;
    }

    for(int i = 1; i <= 3 && i < leftStr.size(); ++i){
        string s = midRes;
        string str = leftStr.substr(0, i);
        int num = atoi(str.c_str());
        if(num > 255 || (num > 0 && str[0] == '0') || (num == 0 && str.size() > 1))
            continue;
        string left = leftStr.substr(i);
        s = s + str + '.';
        Handle(res, s, left, n - 1);
    }
}

int main()
{
    string s = "010010";
    vector<string> str;
    string midRes;
    Handle(str, midRes, s, 3);
    PrintVector(str);
}