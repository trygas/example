#include <iostream>
#include <vector>

#include "general.h"

int main()
{
    SegmentTreeNode *root = new SegmentTreeNode(1, 6);
    root = root->Build(1, 6);
    root->PrintFirst();
}