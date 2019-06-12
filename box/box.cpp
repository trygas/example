#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int rows = 4, cols = 4;
    vector<string> box = {".oxo", "o..o", ".xox", "xoxo"};
    vector<string> change;
    vector<string> result;

    for (int i = 0; i < cols; ++i)
    {
        string str1;

        for (int j = 0; j < rows; ++j)
        {
            str1 += box[j][i];
        }

        change.push_back(str1);
    }

    for (int i = 0; i < cols; ++i)
    {
        cout << change[i] << endl;
    }

    cout << endl;

    for (int i = 0; i < cols; ++i)
    {
        vector<int> hind_index;
        vector<int> box_index;

        for (int j = rows - 1; j >= 0; --j)
        {
            if (change[i][j] == 'x')
                hind_index.push_back(j);
            else if (change[i][j] == 'o')
            {
                box_index.push_back(j);
            }
        }

        string str1(rows, '.');
        int index = 0;

        for (int j = 0; j < hind_index.size(); ++j)
        {
            str1[hind_index[j]] = 'x';

            for (int k = index; k < box_index.size(); ++k)
            {
                if (box_index[k] > hind_index[j])
                {
                    index = k;
                    break;
                }
                else
                {
                    str1[hind_index[j] - (k - index) - 1] = 'o';
                }
            }
        }

        result.push_back(str1);
    }

    for (int i = 0; i < cols; ++i)
    {
        cout << result[i] << endl;
    }
}