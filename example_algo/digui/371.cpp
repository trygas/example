#include "general.h"

void num(int n, int ans, vector<int> &result){
    if(n == 0){
        if(ans > 0){
            result.push_back(ans);
        }
        return;
    }
    for(int i = 0; i <= 9; i ++){
        num(n - 1, ans * 10 + i, result);
    }
}


vector<int> numbersByRecursion(int n)
{
    vector<int> res;
    num(n, 0, res);
    return res;
}

int main()
{
    PrintVector(numbersByRecursion(3));
}