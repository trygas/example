#include "general.h"

int main()
{
    int num = 5;

    vector<int> n(1, 1);
    vector<int> res(num + 1, 0);
    for(int i = 1; i <= num; ++i){
        if (n.back() == i){
            res[i] = 1;
            n.emplace_back(n.back() * 2);
            continue;
        }
        else{
            res[i] = 1 + res[i - n[n.size() - 2]];
        }
    }

    PrintVector(res);
}
