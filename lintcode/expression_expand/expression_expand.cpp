#include <iostream>
#include <vector>
#include <stack>

using namespace std;

string solve(string &str1)
{
    string res = "", t = "";
    stack<int> s_num;
    stack<string> s_str;
    int cnt = 0;

    for (int i = 0; i < str1.size(); ++i)
    {
        if (str1[i] >= '0' && str1[i] <= '9')
        {
            cnt = 10 * cnt + str1[i] - '0';
        }
        else if (str1[i] == '[')
        {
            s_num.push(cnt);
            s_str.push(t);
            cnt = 0;
            t.clear();
        }
        else if(str1[i] == ']')
        {
            int k = s_num.top();
            s_num.pop();

            for (int j = 0; j < k; ++j)
            {
                s_str.top() += t;
            }

            t = s_str.top();
            s_str.pop();
        }
        else
        {
            t += str1[i];
        }
    }

    return s_str.empty() ? t : s_str.top();
}

int main()
{
    string str1 = "3[2[ad]3[pf]]xyz";
    cout << solve(str1);
}