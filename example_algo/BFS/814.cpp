#include "general.h"

int Handle(vector<UndirectedGraphNode*> graph, UndirectedGraphNode* A,
           UndirectedGraphNode* B)
{
    queue<UndirectedGraphNode*> q;
    q.push(A);

    map<UndirectedGraphNode*, bool> map;
    map[A] = true;
    int level = 0;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            UndirectedGraphNode* node = q.front();
            q.pop();

            if(node == B)
                return level;
            for(auto& n: node->neighbors){
                if(!map[n]){
                    q.push(n);
                    map[n] = true;
                }
            }
        }

        level++;
    }

    return 0;
}

int main()
{

}