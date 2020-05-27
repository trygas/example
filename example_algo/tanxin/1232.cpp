#include "general.h"

int main()
{
    vector<vector<int> > points = {{0, 9}, {1, 8}, {7, 8}, {1, 6},
                                   {9, 16}, {7, 13}, {7, 10}, {6, 11},
                                   {6, 9}, {9, 13}};

    sort(points.begin(), points.end(), [](auto &a, auto &b){
        return a[0] < b[0];
    });

    int res = 1;
    int left = points[0][1];
    for(int i = 1; i < points.size(); ++i){
        if(points[i][0] <= left){
            if(left > points[i][1])
                left = points[i][1];
            continue;
        }
        else{
            res++;
            left = points[i][1];
        }
    }

    cout << res;
}