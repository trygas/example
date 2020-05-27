#include "general.h"

/*
 * 如果要将N个盘从A移动到C:
 * 1. 先把前N-1个盘从A移动到B
 * 2. 然后把最大盘从A移动到C
 * 3. 最后把N-1个盘从B移动到C
 */

vector<string> step;

void Move(vector<string> &res, char m, char n)
{
    switch(m){
        case 'A': res.push_back(step[n == 'B' ? 0 : 1]);
            break;
        case 'B': res.push_back(step[n == 'A' ? 2 : 3]);
            break;
        case 'C': res.push_back(step[n == 'A' ? 4 : 5]);
            break;
    }
}

void hanoi(vector<string> &result, int n,
           char a, char b, char c)
{
    if(n == 1)
        Move(result, a, c);
    else{
        hanoi(result, n - 1, a, c, b);
        Move(result, a, c);
        hanoi(result, n - 1, b, a, c);
    }
}

int main()
{
    vector<string> res;
    step.push_back("from A to B");
    step.push_back("from A to C");
    step.push_back("from B to A");
    step.push_back("from B to C");
    step.push_back("from C to A");
    step.push_back("from C to B");
    hanoi(res, 3, 'A', 'B', 'C');
    PrintVector(res);
}