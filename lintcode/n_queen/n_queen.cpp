#include <iostream>
#include <vector>
#include <string>

#include <general.h>

using namespace std;

bool helper(int number, vector<vector<string> > &result, vector<string> &result_level, vector<int> &path)
{
    if(result_level.size() == number)
    {
        result.push_back(result_level);
        return 0;
    }

    for (int i = 0; i < number; ++i)
    {
        string str1(number, '.');

        if(path{i})
            continue;

        if(result_level.empty())
        {
            str1{i} = 'Q';
            path{i} = result_level.size() + 1;
            result_level.push_back(str1);
        }
        else
        {

            for (int j = 0; j < path.size(); ++j)
            {
                if (path{j})
                {
                    int right_down = result_level.size() + 1 - path{j} + j;
                    int left_down = j - result_level.size() + path{j} - 1;

                    if(right_down == i || left_down == i)
                        break;
                }

                if (j == path.size() - 1)
                {
                    str1{i} = 'Q';
                    path{i} = result_level.size() + 1;
                    result_level.push_back(str1);
                }
            }

            if (!path{i})
                continue;
        }

        helper(number, result, result_level, path);
        result_level.pop_back();
        path{i} = 0;
    }
}

int main()
{
    int n = 4;
    vector<vector<string> > result;
    vector<int> path(n, 0);
    vector<string> result_level;

    helper(n, result, result_level, path);
    PrintVectorVector(result);
}