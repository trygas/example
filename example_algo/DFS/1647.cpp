#include "general.h"

vector<vector<int>> ans;
vector<int> edge[510], tem;
bool vis[510];

void dfs(int now, int aim) {
    if (now == aim) {
        ans.push_back(tem);
        return;
    }
    int siz = edge[now].size();
    for (int i = 0; i < siz; i++) {
        int nxt = edge[now][i];
        if (vis[nxt]) continue;
        vis[nxt] = 1;
        tem.push_back(nxt);
        dfs(nxt, aim);
        tem.pop_back();
        vis[nxt] = 0;
    }
}

vector<vector<int>> getPath(int n, vector<vector<int>> &G, int S, int T) {
    // Write your code here
    int m = G.size();
    for (int i = 0; i < n; i++) {
        edge[i].clear();
        vis[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int u = G[i][0], v = G[i][1];
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for (int i = 0; i < n; i++) sort(edge[i].begin(), edge[i].end());
    ans.clear();
    tem.clear();
    tem.push_back(S);
    vis[S] = 1;
    dfs(S, T);
    return ans;
}


int main()
{
    int n = 4;
    vector<vector<int> > G = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {3, 2}};
    int S = 0;
    int T = 2;
}