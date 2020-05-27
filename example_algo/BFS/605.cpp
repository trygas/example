#include "general.h"

bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs)
{
    map<int, int> pos, pre;

    for(int i = 0; i < org.size(); ++i){
        pos[org[i]] = i;
    }

    for(auto seq: seqs){
        for(int i = 0; i < seq.size(); ++i){
            if(!pos.count(seq[i]))
                return false;

            if(!pre.count(seq[i]))
                pre[seq[i]] = (i == 0 ? -1 : seq[i - 1]);
            else
                pre[seq[i]] = std::max(pre[seq[i]], (i == 0 ? -1 : seq[i - 1]));
        }
    }

    if(!org.empty() && pre[org[0]] != -1)
        return false;
    for(int i = 1; i < org.size(); ++i){
        if(pre[org[i]] != org[i - 1])
            return false;
    }

    return true;
}

int main()
{
    vector<int> org = {1, 2, 3};
    vector<vector<int> > seqs = {{1, 2}, {1, 3}};

    return sequenceReconstruction(org, seqs);
}