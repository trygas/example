#include "general.h"

void Handle(int N, int index, int &sum, vector<bool> &visited)
{
    if(index == N + 1){
        sum++;
        return;
    }
    for(int i = 1; i <= N; ++i){
        if(visited[i - 1])
            continue;
        if(i % index == 0 || index % i == 0){
            visited[i - 1] = true;
            Handle(N, index + 1, sum, visited);
            visited[i - 1] = false;
        }
    }
}

int main()
{
    int N = 3;
    int sum = 0;
    vector<bool> visited(N, false);
    Handle(N, 1, sum, visited);
    cout << sum << endl;
}