#include "general.h"

int solve(string &string1, string &string2)
{
    if (string1.empty() || string2.empty())
        return 0;

    vector<vector<int > > result(string1.size(), vector<int>(string2.size(), 0));

    for (int i = 0; i < string1.size(); ++i)
    {
        int max_string = 0;
        int index_string1 = i;

        for (int j = 0; j < string2.size(); ++j)
        {
            if (string1[index_string1] == string2[j])
            {
                index_string1++;
                max_string++;

                if (max_string > result[i][j - 1])
                    result[i][j] = max_string;
                else
                    result[i][j] = result[i][j - 1];
            }
            else
            {
                max_string = 0;
                index_string1 = i;

                if (string1[i] == string2[j])
                {
                    max_string = 1;
                    index_string1 = i + 1;
                }

                if (j != 0)
                    result[i][j] = result[i][j - 1];
            }
        }
    }

    int max_num = 0;

    for (int k = 0; k < string1.size(); ++k)
    {
        max_num = max(max_num, result[k][string2.size() - 1]);
    }

    PrintVectorVector(result);
    return max_num;
}

int main()
{
    string string1 = "dnfsd";
    string string2 = "ddnf";

    return solve(string1, string2);
}