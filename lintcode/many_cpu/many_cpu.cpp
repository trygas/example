#include "general.h"

int main()
{
    vector<int> homework{1, 1, 1, 1, 1, 2, 2};

    int processorNum = 1;
    int homeworkNum = homework.size();

    sort(homework.begin(), homework.end());

    int res = homeworkNum % processorNum;
    int sum = 0;

    for (int i = homeworkNum - 1; i >= processorNum - 1; )
    {
        sum += homework[i];
        i -= processorNum;
    }
    if (res)
        sum += homework[res - 1];

    cout << sum;
}
