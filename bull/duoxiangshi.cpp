#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> first(10);
    vector<int> second(10);

    for(int i = 0; i < 10; ++i)
    {
        cin >> first[i];
    }
    for(int i = 0; i < 10; ++i)
    {
        cin >> second[i];
    }

    int first_level = 4;
    int second_level = 4;

    for(int i = 0; i < 10; i += 2)
    {
        if(first[i] == 0 && first[i + 1] == 0)
            first_level -= (i + 2) / 2;

        if(second[i] == 0 && second[i + 1] == 0)
            second_level -= (i + 2) / 2;
    }

    int result_level = first_level + second_level;
    vector<int> result;
    result.resize((result_level + 1) * 2);

    for(int i = result_level; i >= 0; --i)
    {
        for(int j = first_level; j >= 0; --j)
        {
            int k = i - j;
            if(k > 4 || k < 0)
                continue;

            int a = first[8 - j * 2];
            int b = first[9 - j * 2];
            int c = second[8 - k * 2];
            int d = second[9 - k * 2];
            int level_a = (result_level - i) * 2;
            int level_b = (result_level - i) * 2 + 1;
            result[level_a] += (a * c - b * d);
            result[level_b] += (a * d + b * c);
        }
    }

    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << endl;
    }
}