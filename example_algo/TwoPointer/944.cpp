#include "general.h"

int findMaxVector(vector<int> &vec)
{
    int res = 0;
    for(int i = 0; i < vec.size(); ++i){
        if(vec[i] < 0)
            continue;
        int sum = vec[i];
        res = std::max(res, sum);
        for(int j = i + 1; j < vec.size(); ++j){
            sum += vec[j];
            res = std::max(res, sum);
            if(sum < 0)
                break;
        }
    }

    return res;
}

int maxSubmatrix(vector<vector<int>> &matrix)
{
    int res = 0;
    for(int i = 0; i < matrix.size(); ++i){
        for(int j = i; j < matrix.size(); ++j){
            vector<int> sum(matrix[0].size(), 0);
            for(int k = 0; k < matrix[0].size(); ++k){
                for(int m = i; m <= j; ++m){
                    sum[k] += matrix[m][k];
                }
            }

            res = std::max(res, findMaxVector(sum));
        }
    }

    return res;
}

int main()
{
    vector<vector<int> > matrix = {{1, 3, -1}, {2, 3, -2}, {-1, -2, -3}};
    return maxSubmatrix(matrix);
}
