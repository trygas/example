#include "general.h"

int minimumNumberofRefuelingStops(int target, int startFuel, vector<vector<int>> &stations)
{
    int n = stations.size();
    stations.push_back({target, 0});
    stations.push_back({0, 0});
    sort(stations.begin(), stations.end(), [](vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    });

    vector<vector<int> > res(n + 2, vector<int>(n + 2, -1));
    res[0][0] = startFuel;
    if(stations[1][0] - stations[0][0] <= res[0][0])
        res[1][0] = res[0][0] - (stations[1][0] - stations[0][0]);
    else
        return -1;

    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= i - 1; ++j){
            if(res[i][j] >= 0){
                if(res[i][j] >= stations[i + 1][0] - stations[i][0])
                    res[i + 1][j] = std::max(res[i + 1][j], res[i][j] - (stations[i + 1][0] - stations[i][0]));
                if(res[i][j] + stations[i][1] > stations[i + 1][0] - stations[i][0])
                    res[i + 1][j + 1] = std::max(res[i + 1][j + 1], res[i][j] + stations[i][1] - (stations[i + 1][0] - stations[i][0]));
            }
        }
    }

    for(int i = 0; i <= n + 1; ++i){
        if(res[n + 1][i] >= 0)
            return i;
    }
    return -1;
}

int main()
{
    int target = 100, startFuel = 10;
    vector<vector<int> > station = {{10, 60}, {20, 30}, {30, 30}, {60, 40}};

    cout << minimumNumberofRefuelingStops(target, startFuel, station);
}
