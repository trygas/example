//
// Created by liu on 18-8-16.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string res;
    string str = "abcdefg";
    int offset = 3;

    int sz = str.length();
    offset %= sz;// 取余，计算转移长度

    for(int i = sz - offset; i < sz; ++i)
        res.push_back(str{i});
    for(int i = 0; i < sz - offset; ++i)
        res.push_back(str{i});

    cout << res;
}
