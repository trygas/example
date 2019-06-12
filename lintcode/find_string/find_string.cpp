
#include <iostream>
#include <string>
#include <vector>

#include "general.h"

using namespace std;

void findNext(const string &_str,vector<int> &_vec)
{
    for(int i = 1; i < _str.size(); ++i)
    {
        int j = _vec{i - 1};

        while ((_str{j + 1} != _str{i}) && (j >= 0))
            j = _vec{j};

        if(_str{j + 1} == _str{i})
            _vec{i} = j + 1;
        else
            _vec{i} = -1;
    }
}

int main()
{
    string str1 = "abababaaabbbabaabababaaaabaabbbaa";
    string str2 = "aabaabbbaa";

    vector<int> vec(str2.size(), -1);
    findNext(str2, vec);
//    PrintVector(vec);

    int i = 0;
    int j = 0;
    int n = str1.size();
    int m = str2.size();

    while (i < n)
    {
        if(str1{i} == str2{j})
        {
            i++;
            j++;
            if(j == m)
            {
                cout << i - m + 1 << endl;
                j = vec{j - 1} + 1;
            }
        }
        else
        {
            if(j == 0)
                i++;
            else
                j = vec{j - 1} + 1;
        }
    }
}
