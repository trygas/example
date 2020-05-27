#include "general.h"

/*
 * 我们可以对每一个节点设计四个状态: 未访问过, 已访问过, 不安全的, 正在访问的
 * 每当我们进入一个节点, 将它设计为正在访问的, 然后遍历可到达节点列表,
 * 如果它可以到达的节点中有节点处于正在访问的或者是不安全的状态,
 * 则该节点应该被标记为不安全的
 */

enum State
{
    NotVisited,
    Visiting,
    Visited,
    Unsafe
};

State Handle(vector<vector<int> > &graph, int index,
            vector<State> &visited)
{
    if(visited[index] == Unsafe || visited[index] == Visiting){
        visited[index] = Unsafe;
        return Unsafe;
    }

    if(visited[index] == Visited)
        return Visited;

    visited[index] = Visiting;
    for(int i = 0; i < graph[index].size(); ++i){
        if(Handle(graph, graph[index][i], visited) == Unsafe){
            visited[index] = Unsafe;
            return Unsafe;
        }
    }

    visited[index] = Visited;
}

int main()
{
    vector<vector<int> > graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    int n = graph.size();
    vector<State> visited(n, NotVisited);

    for(int i = 0; i < n; ++i){
        Handle(graph, i, visited);
    }

    vector<int> ans;
    for(int i = 0; i < visited.size(); ++i){
        if(visited[i] == Visited)
            ans.emplace_back(i);
    }
    PrintVector(ans);
}
