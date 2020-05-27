#include "general.h"

int main()
{
    string s = "eqgkcwGFvjjmxutystqdfhuMblWbylgjxsxgnoh";
    int k = 16;

    int curDiffCha = 0;
    map<char, int> chaNum;

    int left = 0, maxLength = 0, resLeft = 0;

    for(int i = 0; i < s.size(); ++i){
        chaNum[s[i]]++;
        if(chaNum[s[i]] == 1){
            curDiffCha++;
        }
        if(curDiffCha == k){
            if(i - left > maxLength){
                resLeft = left;
                maxLength = i - left;
            }
        }
        else if(curDiffCha == k + 1){
            for(int j = left; j < i; ++j){
                chaNum[s[j]]--;
                if(chaNum[s[j]] == 0){
                    curDiffCha--;
                    left = j + 1;
                    break;
                }
            }
        }
    }

    if(maxLength == 0)
        cout << s;
    cout << s.substr(resLeft, maxLength + 1);
}