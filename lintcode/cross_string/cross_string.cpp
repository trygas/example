//描述：给出三个字符串:s1、s2、s3，判断s3是否由s1和s2交叉构成。

//思路：使用DP算法

#include "general.h"

bool solve(string str1, string str2, string str3)
{
    int str1_length = str1.size();
    int str2_length = str2.size();
    int str3_length = str3.size();

    if (str3_length != str1_length + str2_length)
        return 0;

    vector<vector<int> > data (str1_length + 1, vector<int>(str2_length + 1, 0));
    data[0][0] = 1;

    for (int i = 1; i <= str1_length; ++i)
    {
        if (str3[i - 1] == str1[i - 1] && data[i - 1][0])
            data[i][0] = 1;
    }
    for (int j = 1; j <= str2_length; ++j)
    {
        if (str3[j - 1] == str2[j - 1] && data[0][j - 1])
            data[0][j] = 1;
    }

    for (int i = 1; i <= str1_length; ++i)
    {
        for (int j = 1; j <= str2_length; ++j)
        {
            if (str1[i - 1] == str3[i + j - 1] && data[i - 1][j])
            {
                data[i][j] = true;
            }
            if (str2[j - 1] == str3[i + j - 1] && data[i][j - 1])
            {
                data[i][j] = true;
            }
        }
    }

    return data[str1_length][str2_length];
}

int main()
{
    string str1 = "aabcc", str2 = "dbbca";
    string str3 = "aadbbcbcac";

    cout << solve(str1, str2, str3);
}