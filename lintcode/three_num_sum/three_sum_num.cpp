#include "general.h"

struct ThreeNum
{
    ThreeNum(int _x, int _y, int _z):x(_x), y(_y), z(_z)
    {}

    friend ostream &operator << (ostream &output, const ThreeNum& threeNum)
    {
        output << threeNum.x << " " << threeNum.y << " " << threeNum.z << endl;
        return output;
    }

    int x;
    int y;
    int z;
};

void Solve(vector<int> &data, vector<ThreeNum> &result)
{
//    sort(data.begin(), data.end());
//    data.erase(unique(data.begin(), data.end()), data.end());
//    PrintVector(data);
//
//    for (int i = 0; data[i] < 0; ++i)
//    {
//        for (int j = data.size() - 1; data[j] > 0; --j)
//        {
//            int num = -(data[i] + data[j]);
//            auto index = find(data.begin() + i + 1, data.begin() + j, num);
//
//            if (index < data.begin() + j)
//            {
//                ThreeNum threeNum(data[i], *index, data[j]);
//                result.push_back(threeNum);
//            }
//        }
//    }
//
//    PrintVector(result);

    sort(data.begin(), data.end());

    for (int i = 0; i < data.size(); ++i)
    {
        if (i > 0 && data[i - 1] == data[i])
            continue;

        int start = i + 1, end = data.size() - 1;
        int target = -data[i];

        while (start < end)
        {
            if (start > i + 1 && data[start - 1] == data[start])
            {
                start++;
                continue;
            }

            if (target > data[start] + data[end])
                start++;
            else if (target < data[start] + data[end])
                end--;
            else
            {
                result.push_back(ThreeNum(data[i], data[start], data[end]));
                start++;
            }
        }
    }

    PrintVector(result);
}

int main()
{
    vector<int> data = {-2,-3,-4,-5,-100,99,1,4,4,4,5,1,0,-1,2,3,4,5};
    vector<ThreeNum> result;
    Solve(data, result);
}