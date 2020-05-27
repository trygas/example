#include "general.h"

//vector<string> str = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS",
//                      "TUV", "WXYZ"};



void Handle(string& digits, vector<string> &res, int index,
            map<char, string> &str, string midRes)
{
    if(index == digits.size()){
        res.push_back(midRes);
        return;
    }
    string subStr = str[digits[index]];
    if(subStr.size() == 0)
        Handle(digits, res, index + 1, str, midRes);
    for(int i = 0; i < subStr.size(); ++i){
        Handle(digits, res, index + 1, str, midRes + subStr[i]);
    }
}

int main()
{
    map<char, string> str;
    str['1'] = "";
    str['2'] = "abc";
    str['3'] = "def";
    str['4'] = "ghi";
    str['5'] = "jkl";
    str['6'] = "mno";
    str['7'] = "pqrs";
    str['8'] = "tuv";
    str['9'] = "wxyz";

    string digits = "23";
    vector<string> res;
    string midRes;
    Handle(digits, res, 0, str, midRes);
    PrintVector(res);
}