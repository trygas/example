#include "general.h"

/*
 * 主要思路是记录一个站可以乘坐哪些巴士
 */
int Handle(vector<vector<int> > &routes, int s, int t)
{
    if(routes.empty())
        return -1;

    if(s == t)
        return 0;

    map<int, vector<int> > stop2bus;
    for(int i = 0; i < routes.size(); ++i){
        for(int j = 0; j < routes[i].size(); ++j){
            stop2bus[routes[i][j]].push_back(i);
        }
    }

    set<int> visited;
    queue<pair<int, int> > q;
    q.push(pair<int, int>(s, 0));
    while (!q.empty()){
        int start = q.front().first;
        int step = q.front().second;
        q.pop();
        for(int bus: stop2bus[start]){
            if(visited.find(bus) != visited.end())
                continue;
            visited.insert(bus);
            for(int stop: routes[bus]){
                if(stop == t) return step + 1;
                if(stop == start) continue;
                q.push({stop, step + 1});
            }
        }
    }

    return -1;
}

int main()
{
    vector<vector<int> > routes = {{1, 2, 7}, {3,  6, 7}};
    int S = 1;
    int T = 6;

    cout << Handle(routes, S, T);
}
