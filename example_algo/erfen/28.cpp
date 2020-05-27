#include "general.h"

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int sum = m * n;

    int left = 0, right = sum;
    int mid = sum / 2;
    while(right >= left){
        int x = mid / n;
        int y = mid % n;

        if(x >= m || y >= n)
            return false;
        if(matrix[x][y] == target)
            return true;
        else if(matrix[x][y] > target){
            right = mid - 1;
            mid = (right + left) / 2;
        }
        else{
            left = mid + 1;
            mid = (right + left) / 2;
        }
    }
    return false;
}

int main()
{
    vector<vector<int> > matrix = {{1,5,8,12,13,15,18,20,25,26,28,33,38,40,43,49,52,53,59},
                                   {84,100,110,129,141,156,177,198,220,242,254,266,284,297,316,326,343,358,373},
                                   {388,398,419,439,449,460,472,495,516,539,560,582,600,610,624,643,668,691,710},
                                   {720,733,751,765,787,804,814,832,856,880,905,930,950,974,999,1012,1022,1039,1061},
                                   {1081,1091,1102,1126,1151,1175,1194,1219,1239,1253,1263,1274,1287,1298,1308,1318,1337,1361,1382},
                                   {1404,1417,1437,1452,1466,1487,1503,1518,1537,1555,1578,1590,1601,1613,1636,1659,1669,1688,1712}};
    int target = 1888;
    searchMatrix(matrix, target);
}
