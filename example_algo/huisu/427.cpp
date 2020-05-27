#include "general.h"

/*
 * 1. 如果当前右括号数量等于n, 那么当前字符串为一种组合
 * 2. 如果左括号等于n, 那么就要填充右括号为n
 * 3. 如果左括号未多于n, 则
 *   3.1 如果左括号大于右括号, 则可以添加一个左括号或右括号
 *   3.2 如果左括号不多于右括号, 则只能添加一个左括号.
 */
void Handle(vector<string> &res, string midRes, int l, int r, int n)
{
    if(r == n)
        res.push_back(midRes);
    else if(l == n)
        res.push_back(midRes + string(n - r, ')'));
    else{
        if(l > r)
            Handle(res, midRes + ')', l, r + 1, n);
        Handle(res, midRes + '(', l + 1, r, n);
    }
}

int main()
{
    int n = 3;
    vector<string> res;
    string midRes;
    Handle(res, midRes, 0, 0, n);
    PrintVector(res);
}