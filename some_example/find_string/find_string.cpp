#include "general.h"

void findString(string str, vector<string>& output, int index, bool isWrong = 0)
{
    if (isWrong)
        return;
    else
    {
        int idx = str.find(',', index);
        if (idx == std::string::npos)
        {
            if (str[0] == '\"' && str[str.size() - 1] == '\"')
            {
                string string1 = str.substr(1);
                string outputStr = string1.substr(0, string1.length() - 1);

                int subStrIdx = outputStr.find("\"");
                string insertStr;
                while (subStrIdx != string::npos)
                {
                    insertStr += outputStr.substr(0, subStrIdx+1);
                    outputStr = outputStr.substr(subStrIdx+1);
                    subStrIdx = outputStr.find("\"");
                }
                output.push_back(insertStr);
            }
            else if (str[0] == '\"' || str[str.size() - 1] == '\"')
            {
                isWrong = 1;
                return;
            }
            else
            {
                if (str.find("\"") != string::npos)
                {
                    isWrong = 1;
                    return;
                }
                else
                {
                    output.push_back(str);
                }
            }
        }
        else
        {
            if (str[0] != '\"')
            {
                string firstStr = str.substr(0, idx);
                string secondStr = str.substr(idx + 1);
                findString(firstStr, output, isWrong);
                findString(secondStr, output, isWrong);
            }
            else
            {
                findString(str, output, idx+1, isWrong);
            }
        }
    }
}

int main()
{
    string str("a,,1,\"b,\"\"");
    int sum = 0;
    vector<string> output;
    bool isWrong = 0;

    if (str.empty())
        return 0;
    findString(str, output, 0, isWrong);
    PrintVector(output);
}