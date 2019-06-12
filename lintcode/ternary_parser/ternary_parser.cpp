#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

string solve(string &string1)
{
    stack<string> stack1;

    for (int i = string1.size() - 1; i >= 0; --i)
    {
        if(string1[i] == ':')
            continue;
        else if(string1[i] == '?')
        {
            string left = stack1.top();
            stack1.pop();

            string right = stack1.top();
            stack1.pop();

            if(string1[i - 1] == 'T')
            {
                stack1.push(left);
            }
            else
            {
                stack1.push(right);
            }

            i--;
        }
        else
        {
            char char1 = string1[i];
            string str1;
            stringstream stream;
            stream << char1;
            stack1.push(stream.str());
        }
    }

    return stack1.top();
}

int main()
{
    string string1 = "T?T?F:5:3";

    cout << solve(string1);
}