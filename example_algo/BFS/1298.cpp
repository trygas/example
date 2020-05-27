#include "general.h"

vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
{
    // Wirte your code here
    map<int, set<int> > newEdge;
    map<int, int> indegrees;

    for(int i = 0; i < edges.size(); ++i){
        newEdge[edges[i][0]].insert(edges[i][1]);
        newEdge[edges[i][1]].insert(edges[i][0]);
        indegrees[edges[i][0]]++;
        indegrees[edges[i][1]]++;
    }

    vector<bool> visited(n, false);
    queue<int> q;
    for(auto iter: indegrees){
        if(iter.second == 1){
            q.push(iter.first);
            visited[iter.first] = true;
        }
    }

    vector<int> ans;
    while(!q.empty()){
        ans.clear();
        int size = q.size();
        for(int i = 0; i < size; ++i){
            int index = q.front();
            q.pop();
            ans.push_back(index);

            for(auto node: newEdge[index]){
                if(!visited[node]){
                    newEdge[node].erase(index);
                    indegrees[node]--;

                    if(indegrees[node] <= 1){
                        visited[node] = true;
                        q.push(node);
                    }
                }
            }
        }
    }

    return ans;
}

int main()
{
    int n = 2;
    vector<vector<int> > edges = {{0, 1}};

    PrintVector(findMinHeightTrees(n, edges));
}

