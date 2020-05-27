#include "general.h"

bool Handle(vector<vector<int> > &rooms, int index, vector<bool> &visited)
{
    visited[index] = true;
    for(int i = 0; i < rooms[index].size(); ++i){
        if (visited[rooms[index][i]])
            continue;
        else{
            Handle(rooms, rooms[index][i], visited);
        }
    }
}

bool Count(vector<bool> &visited)
{
    for(bool b: visited){
        if (!b)
            return false;
    }
    return true;
}

int main()
{
    vector<vector<int> > rooms = {{1}, {2}, {3}, {0}};

    vector<bool> visited(rooms.size(), false);
    Handle(rooms, 0, visited);
    PrintVector(visited);
}
