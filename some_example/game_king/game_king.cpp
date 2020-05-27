#include "general.h"

int main()
{
    int time = 4;
    vector<pair<int, int> > question = {make_pair(10, 2), make_pair(38, 3), make_pair(10, 2)};
    vector<pair<int, int> > result;
    result.resize(time + 1, make_pair(0, 0));

    for (int i = 0; i < question.size(); ++i)
    {
        if (result[question[i].second].first == question[i].first)
            result[question[i].second].second += 1;
        else if(result[question[i].second].first < question[i].first)
        {
            result[question[i].second].first = question[i].first;
            result[question[i].second].second = 1;
        }
    }

    for (int l = 1; l < result.size(); ++l)
    {
        for (int i = 0; i < l; ++i)
        {
            if (result[l - i].second == 0)
            {
                continue;
            }
            if (result[l].first < result[i].first + result[l - i].first)
            {
                result[l - 1].second -= 1;
                result[l].first = result[i].first + result[l - i].first;
                result[l].second += 1;
            }
        }
    }

    cout << result[time].first;
}