#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#include "general.h"

using namespace std;

void solve(vector<string> &question, vector<string> &result)
{
    map<string, int> word;

    for (int i = 0; i < question.size(); ++i)
    {
        string string1 = question[i];
        sort(string1.begin(), string1.end());

        word[string1]++;
    }

    for (int i = 0; i < question.size(); ++i)
    {
        string string1 = question[i];
        sort(string1.begin(), string1.end());

        if (word[string1] > 1)
        {
            result.push_back(question[i]);
        }
    }
}

int main()
{
    vector<string> vector_string = {"lint", "intl", "inlt", "code"};
    vector<string> result;

    solve(vector_string, result);

    PrintVector(result);
}