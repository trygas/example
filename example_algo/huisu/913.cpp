#include "general.h"

bool Handle(string s)
{
    for(int i = 0; i < s.size() - 1; ++i){
        if(s[i] == '+' && s[i + 1] == '+'){
            s[i] = '-';
            s[i + 1] = '-';
            if(!Handle(s))
                return true;
            s[i] = '+';
            s[i + 1] = '+';
        }
    }

    return false;
}

int main()
{
    string s = "++++";
    return Handle(s);
}