#include "general.h"

int main()
{
    DirectedGraphNode* root = new DirectedGraphNode(0);
    DirectedGraphNode* num1 = new DirectedGraphNode(1);
    DirectedGraphNode* num2 = new DirectedGraphNode(2);
    DirectedGraphNode* num3 = new DirectedGraphNode(3);
    DirectedGraphNode* num4 = new DirectedGraphNode(4);

    root->neighbors.push_back(num1);
    root->neighbors.push_back(num2);
    num1->neighbors.push_back(num2);
    num1->neighbors.push_back(num3);
    num2->neighbors.push_back(num4);

    map<DirectedGraphNode*, bool> map;
    queue<DirectedGraphNode*> q;
    q.push(num1);
    map[num1] = true;
    while (!q.empty()){
        DirectedGraphNode* node = q.front();
        q.pop();
        if(node == num4)
            return 1;

        for(auto& n: node->neighbors){
            if(!map[n]){
                q.push(n);
                map[n] = true;
            }
        }
    }

    return 0;
}