#include "general.h"

/*
 * 主要思路就是遍历整个图, 将相邻的节点染成不同的颜色, 如果可以完成整个遍历,则说明是二分图
 */
bool colored(int now, vector<vector<int> > &graph, vector<int> &color, int c)
{
    color[now] = c;
    for(int next: graph[now]){
        if(!color[next] && !colored(next, graph, color, -c)){
            return false;
        }
        else if (color[next] == c){
            return false;
        }
    }

    return true;
}

int main()
{
    vector<vector<int> > graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};

    int n = graph.size();
    vector<int> color(n, 0);
    for(int i = 0; i < n; ++i){
        if(!color[i] && !colored(i, graph, color, 1)){
            return false;
        }
    }

    return true;
}
