#include <iostream>
#include <vector>

#include "general.h"

using namespace std;

int main()
{
    vector<int> vector1 = {3, 2, 1, 4};
    SegmentTreeNode* root = new SegmentTreeNode();
    root = root->Build(vector1, 0, vector1.size() - 1);
    root->Modify(root, 3, 0);
    root->PrintFirst();
}