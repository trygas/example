#include "general.h"

bool isValid(string &s)
{
    if (s == "")
    {
        return true;
    }
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(') {
            count++;
        }
        else if (s[i] == ')')
        {
            count--;
        }
        if (count < 0)
        {
            return false;
        }
    }
    return count == 0;
}

void dfs(vector<string> &res, string &s, int left, int right, int begin)
{
    if (left == 0 && right == 0)
    {
        if (isValid(s))
        {
            res.push_back(s);
        }
        return;
    }
    for (int i = begin; i < s.size(); i++)
    {
        if (i > begin && s[i] == s[i - 1])
        {
            continue;
        }
        if (s[i] == '(' && left > 0)
        {
            string newStr = s.substr(0, i) + s.substr(i + 1);
            dfs(res, newStr, left - 1, right, i);
        }
        if (s[i] == ')' && right > 0)
        {
            string newStr = s.substr(0, i) + s.substr(i + 1);
            dfs(res, newStr, left, right - 1, i);
        }
    }
}



vector<string> removeInvalidParentheses(string &s) {
    vector<string> res;
    if (s == "")
    {
        res.push_back("");
        return res;
    }
    int left = 0, right = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            left++;
        }
        else if (s[i] == ')')
        {
            if (left > 0)
            {
                left--;
            }
            else
            {
                right++;
            }
        }
    }
    dfs(res, s, left, right, 0);
    return res;
}


int main()
{
    string s = "()())()";


}