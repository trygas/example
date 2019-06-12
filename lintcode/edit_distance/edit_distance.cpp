#include <iostream>
#include <vector>

using namespace std;

int helper(string &word1, string &word2)
{
    vector<vector<int> > distance(word1.size() + 1, vector<int>(word2.size() + 1));

    for (int i = 0; i < word1.size() + 1; ++i)
    {
        distance[i][0] = i;
    }

    for (int i = 0; i < word2.size() + 1; ++i)
    {
        distance[0][i] = i;
    }

    for (int i = 1; i < word1.size() + 1; ++i)
    {
        for (int j = 1; j < word2.size() + 1; ++j)
        {
            if(word1[i - 1] == word2[j - 1])
                distance[i][j] = distance[i - 1][j - 1];

            else
            {
                distance[i][j] = min(distance[i - 1][j], min(distance[i][j - 1], distance[i - 1][j - 1])) + 1;
            }
        }
    }

    return distance[word1.size()][word2.size()];
}

int main()
{
    string word1 = "mart", word2 = "karma";
    cout << helper(word1, word2);
}