#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num = 2;
    while(cin >> num)
    {
        vector<int> shuju(2 * num);

        for(int i = 0; i < num; ++i)
        {
            cin >> shuju[i * 2] >> shuju[i * 2 + 1];
        }
        vector<int> result;

        for (int i = 0; i < num; ++i)
        {
            vector<int> result_per_data;
            int first_bull = shuju[i * 2];
            int month = shuju[i * 2 + 1];

            result_per_data.resize(4);
            result_per_data[0] = first_bull;

            for (int j = 0; j < month; ++j)
            {
                int big_bull = result_per_data[0];
                result_per_data[0] += result_per_data[1];
                result_per_data[1] = result_per_data[2];
                result_per_data[2] = result_per_data[3];
                result_per_data[3] = big_bull;
            }

            result.push_back(result_per_data[0] + result_per_data[1] + result_per_data[2] + result_per_data[3]);
        }
        for(int i = 0; i < result.size(); ++i)
        {
            cout << result[i] << endl;
        }
    }

}