#include "general.h"

int main()
{
    vector<string> strs = {"ABCD", "ABEF", "ACEF"};

    if(strs.size() == 0)
        cout << "";

    string prefix = "";
    for(int i = 0; i < strs[0].length(); ++i){
        for(int j = 1; j < strs.size(); ++j){
            if(strs[j][i] != strs[0][i])
                cout << prefix;
        }

        prefix += strs[0][i];
    }

    cout << prefix;
}