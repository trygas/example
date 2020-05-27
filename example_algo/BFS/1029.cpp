#include "general.h"

/*
 * 使用BFS的思路, 加一个cache, 标志走到某一个dst, 有没有visit过
 * 有的话判断是不是之前的cost更小, 如果是, 则无需继续走下去
 */

struct node
{
    node(int _time, int _money, int _now):
        time(_time), money(_money), now(_now){}
    int time;
    int money;
    int now;
};

int main()
{
    int n = 3;
    vector<vector<int> > flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    int src = 0, dst = 2, K = 0;

    map<int, vector<pair<int, int> > > routes;
    for(int i = 0; i < flights.size(); ++i){
        routes[flights[i][0]].push_back({flights[i][1], flights[i][2]});
    }

    vector<int> money(n, INT32_MAX);
    int min = INT32_MAX;
    queue<node> q;
    q.push(node(K+1, 0, src));
    while(!q.empty()){
        node n = q.front();
        q.pop();
        if(n.time < 0)
            continue;
        if(n.now == dst){
            min = std::min(min, n.money);
        }

        for(auto route: routes[n.now]){
            if(money[route.first] > n.money + route.second){
                q.push(node(n.time-1, n.money+route.second, route.first));
                money[route.first] = n.money + route.second;
            }
        }
    }

    cout << min << endl;
}