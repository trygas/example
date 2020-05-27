#include "general.h"

int handle(string &str1, string &str2)
{
    vector<vector<int> > res(str1.size() + 1, vector<int>(str2.size() + 1));
    for(int i = 0; i <= str1.size(); ++i){
        res[i][0] = 0;
    }
    for(int i = 0; i <= str2.size(); ++i){
        res[0][i] = 0;
    }
    for(int i = 1; i <= str1.size(); ++i){
        for(int j = 1; j <= str2.size(); ++j){
            if (str1[i - 1] == str2[j - 1])
                res[i][j] = res[i - 1][j - 1] + 1;
            else
                res[i][j] = std::max(res[i - 1][j], res[i][j - 1]);
        }
    }

    return res[str1.size()][str2.size()];
}

int main()
{
    string str1 = "bedaacbade";
    string str2 = "dccaeedbeb";

    cout << handle(str1, str2);
}
