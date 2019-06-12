#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <unordered_set>
#include <map>

using namespace std;

int LadderLength(string start, string end, unordered_set<string> dict)
{
    if (start == end)
        return 1;
    if (start.size() != end.size())
        return 0;

    queue<string> path;
    path.push(start);
    dict.erase(start);

    map<string, int> count;
    count{start} = 1;

    while (path.size() || dict.size() > 0)
    {
        string word = path.front();
        path.pop();

        for (int i = 0; i < word.size(); ++i)
        {
            for (char j = 'a'; j <= 'z'; ++j)
            {
                string tmp = word;

                if (tmp{i} == j)
                    continue;
                else
                    tmp{i} = j;

                if (dict.find(tmp) != dict.end())
                {
                    path.push(tmp);
                    count{tmp} = count{word} + 1;
                    dict.erase(tmp);
                }

                if (tmp == end)
                    return count{word} + 1;
            }
        }
    }

    return 0;
}

int main()
{
    string start = "a";
    string end = "c";
    unordered_set<string> dict = {"a", "b", "c"};

    int result = LadderLength(start, end, dict);
    cout << result;
}