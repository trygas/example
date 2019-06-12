#include "general.h"

//void merge(vector<vector<int > > &data, vector<vector<int> > &output)
//{
//    output.push_back(data[0]);
//
//    for (int i = 1; i < data.size(); ++i)
//    {
//        int index = -1;
//
//        for (int j = output.size() - 1; j >= 0; --j)
//        {
//            if (output[j][1] >= data[i][0])
//                index = j;
//            else
//                break;
//        }
//
//        if (index != -1)
//        {
//            vector<vector<int> > new_update;
//
//            for (int k = index; k < output.size(); ++k)
//            {
//                if (output[k][0] <= data[i][0] - 1)
//                    new_update.push_back({output[k][0], data[i][0] - 1, output[k][2]});
//                else if(output[k][0] != data[i][0])
//                    new_update.push_back({data[i][0], output[k][0] - 1, data[i][2]});
//
//                int sum = output[k][2] + data[i][2];
//                if (sum != 0)
//                {
//                    if (output[k][0] >= data[i][0] && output[k][1] <= data[i][1])
//                        new_update.push_back({output[k][0], output[k][1], sum});
//                    else if (output[k][0] <= data[i][0] && output[k][1] >= data[i][1])
//                        new_update.push_back({data[i][0], data[i][1], sum});
//                    else if (data[i][0] <= output[k][1])
//                        new_update.push_back({data[i][0], output[k][1], sum});
//                    else
//                        new_update.push_back({output[k][1], data[i][0], sum});
//                }
//
//                if (output[k][1] + 1 <= data[i][1])
//                    new_update.push_back({output[k][1] + 1, data[i][1], data[i][2]});
//                else if(output[k][1] != data[i][1])
//                    new_update.push_back({data[i][1] + 1, output[k][1], output[k][2]});
//            }
//
//            output.erase(output.begin() + index, output.end());
//            output.insert(output.end(), new_update.begin(), new_update.end());
//        }
//        else
//        {
//            output.push_back(data[i]);
//        }
//    }
//}
//
//vector<int> solve(int length, vector<vector<int > > &update)
//{
//    if (length == 0)
//        return vector<int>();
//
//    if (update.empty())
//        return vector<int>(length, 0);
//
//    vector<vector<int> > merged_data;
//    sort(update.begin(), update.end(), [](vector<int> a, vector<int> b){ return a[0] < b[0];});
//    merge(update, merged_data);
//
//    vector<int> result(length, 0);
//    for (int i = 0; i < merged_data.size(); ++i)
//    {
//        for (int j = merged_data[i][0]; j <= merged_data[i][1]; ++j)
//        {
//            result[j] += merged_data[i][2];
//        }
//    }
//
//    PrintVectorVector(merged_data);
//    cout << endl;
//    PrintVector(result);
//    return result;
//}

vector<int> solve(int length, vector<vector<int> > &update)
{
    if (length == 0)
        return vector<int>();

    if (update.empty())
        return vector<int>(length, 0);

    vector<int> data(length + 1, 0);
    vector<int> res(length, 0);

    for (int i = 0; i < update.size(); ++i)
    {
        int left = update[i][0];
        int right = update[i][1];
        int num = update[i][2];

        data[left] += num;
        data[right + 1] -= num;
    }

    res[0] = data[0];
    for (int j = 1; j < length; ++j)
    {
        res[j] = res[j - 1] + data[j];
    }

    PrintVector(res);
    return res;
}

int main()
{
    int length = 5;
    vector<vector<int> > updata;
    updata.push_back({1, 3, 2});
    updata.push_back({2, 4, 3});
    updata.push_back({0, 2, -2});

    solve(length, updata);
}