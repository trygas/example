#include "general.h"

/*
 * 思路是将字符串看做为一个点, 对于基因库任意两个字符串间所需的突变次数为边权,
 * 原题就能转化为初始串在图中只经过边权为1的边是否能走到结束串的点.
 */
int minMutation(string &start, string &end, vector<string> &bank)
{
    bank.push_back(start);

    int endIndex = -1;
    for(int i = 0; i < bank.size(); ++i){
        if(bank[i] == end){
            endIndex = i;
            break;
        }
    }
    if(endIndex == -1)
        return endIndex;

    vector<vector<int> > adj(bank.size(), vector<int>(bank.size(), 0));
    for(int i = 0; i < bank.size(); ++i){
        for(int j = 0; j < bank.size(); ++j){
            int count = 0;
            for(int k = 0; k < bank[i].size(); ++k){
                if(bank[i][k] != bank[j][k])
                    count++;
            }
            adj[i][j] = count;
        }
    }

    queue<int> q;
    q.push(bank.size() - 1);

    int res = 0;
    set<int> visited;
    while(!q.empty()){
        res++;
        for(int i = q.size(); i > 0; --i){
            int t = q.front();
            q.pop();
            visited.insert(t);
            for(int j = 0; j < bank.size(); ++j){
                if(adj[t][j] != 1 || visited.count(j))
                    continue;
                if(j == endIndex)
                    return res;
                q.push(j);
            }
        }
    }

    return -1;
}

int main()
{
    string start = "AACCGGTT";
    string end = "AACCGGTA";
    vector<string> bank = {"AACCGGTA"};

    cout << minMutation(start, end, bank);
}
