#include "general.h"

/*
 * 遍历图, 统计所有节点的入度, 将所有入度为0的节点推入队列,
 * 每次从队列头部取出一个节点, 将其所有邻居节点的入度减1,
 * 如果减到0, 就把该邻居节点推入队列.
 */

int main()
{
    DirectedGraphNode* root = new DirectedGraphNode(0);
    DirectedGraphNode* num1 = new DirectedGraphNode(1);
    DirectedGraphNode* num2 = new DirectedGraphNode(2);
    DirectedGraphNode* num3 = new DirectedGraphNode(3);
    DirectedGraphNode* num4 = new DirectedGraphNode(4);
    DirectedGraphNode* num5 = new DirectedGraphNode(5);

    root->neighbors.push_back(num1);
    root->neighbors.push_back(num2);
    root->neighbors.push_back(num3);

    num1->neighbors.push_back(num4);
    num2->neighbors.push_back(num4);
    num2->neighbors.push_back(num5);
    num3->neighbors.push_back(num4);
    num3->neighbors.push_back(num5);

    vector<DirectedGraphNode*> graph;
    graph.push_back(root);
    graph.push_back(num1);
    graph.push_back(num2);
    graph.push_back(num3);
    graph.push_back(num4);
    graph.push_back(num5);

    map<DirectedGraphNode*, int> map;
    for(int i = 0; i < graph.size(); ++i){
        for(auto &neighbor: graph[i]->neighbors)
            map[neighbor]++;
    }
    vector<DirectedGraphNode*> res;
    queue<DirectedGraphNode*> q;
    for(auto& node: graph){
        if(map.count(node) == 0){
            q.push(node);
            res.push_back(node);
        }
    }

    while(!q.empty()){
        DirectedGraphNode* node = q.front();
        q.pop();
        for(auto &next: node->neighbors){
            map[next]--;
            if(map[next] == 0){
                q.push(next);
                res.push_back(next);
            }
        }
    }
}