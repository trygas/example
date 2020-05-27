#include "general.h"

int main()
{
    int N = 7;
    vector<int> resA(N + 1, 0), res(N+1, 0), resCC(N + 1, 0), resCV(N + 1, 0);

    for(int i = 1; i <= N; ++i){
        resA[i] = std::max(resA[i-1]+1,  resCV[i-1]+1);
        resCC[i] = std::max(resA[i-1], resCV[i-1]);
        resCV[i] = std::max(resA[i-1], resCC[i-1]*2);
    }

    cout << resA[N] << " " << resCV[N];
}
