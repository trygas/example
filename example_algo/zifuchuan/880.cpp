#include "general.h"

TreeNodeInt* Handle(string &s)
{
    string rootStr;
    string leafStr;
    if(s.empty())
        return nullptr;
    if(s[0] == '-'){
        leafStr = s.substr(2);
        rootStr = s.substr(0, 2);
    }
    else{
        leafStr = s.substr(1);
        rootStr = s.substr(0, 1);
    }

    TreeNodeInt* root = new TreeNodeInt(atoi(rootStr.c_str()));
    int leftBraket = 0;
    for(int i = 0; i < leafStr.size(); ++i)
    {
        if(leafStr[i] == '(')
            leftBraket++;
        else if(leafStr[i] == ')'){
            leftBraket--;
            if(leftBraket == 0){
                string left = leafStr.substr(1, i - 1);
                root->left = Handle(left);
                if(i != leafStr.size() - 1){
                    string right = leafStr.substr(i + 2, leafStr.size() - i - 3);
                    root->right = Handle(right);
                }
                break;
            }
        }
    }

    return root;
}

int main()
{
    string s = "-4(2(3)(1))(6(5))";

    TreeNodeInt* res = Handle(s);
    res->PrintFirst();
}