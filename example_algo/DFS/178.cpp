#include "general.h"

int find(vector<int> &root, int e)
{
    if(root[e] == -1)
        return e;
    else
        return root[e] = find(root, root[e]);
}

int main()
{
    int n = 8;
    vector<vector<int> > edges = {{0, 1}, {1, 2}, {3, 2}, {4, 3}, {4, 5},
                                  {5, 6}, {6, 7}};
    vector<int> visited(n, -1);
    for(int i = 0; i < edges.size(); ++i){
        int root1 = find(visited, edges[i][0]);
        int root2 = find(visited, edges[i][1]);
        if(root1 == root2)
            return false;
        visited[root1] = root2;
    }

    return edges.size() == n - 1;
}
