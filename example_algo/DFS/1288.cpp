#include "general.h"

map<string, multiset<string>> targets;
vector<string> route;

void dfs(string airport)
{
    while(targets[airport].size()){
        string next = *targets[airport].begin();
        targets[airport].erase(targets[airport].begin());
        dfs(next);
    }
    route.emplace_back(airport);
}

vector<string> Handle(vector<vector<string> > &tickets)
{
    for(auto ticket: tickets)
        targets[ticket[0]].insert(ticket[1]);
    dfs("JFK");
    return vector<string>(route.rbegin(), route.rend());
}

int main()
{
    vector<vector<string> > tickets = {{"MUC", "LHR"}, {"JFK", "MUC"},
                                       {"SFO", "SJC"}, {"LHR", "SFO"}};

    PrintVector(Handle(tickets));
}
