#include "general.h"

int numberOfArithmeticSlices(vector<int> &A) {
    // Write your code here
    int result = 0;
    int size = A.size();
    if (size == 0) return 0;
    vector<int> dp(size, 0);
    dp[0] = 1;
    dp[1] = 2;
    for(int i = 2; i < size; i++)
    {
        if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
        {
            dp[i] = dp[i - 1] + 1;
        }
        else dp[i] = 2;
    }
    for(int i = 0; i < size; i++)
    {
        if(dp[i] > 2)
        {
            result += dp[i] - 2;
        }
    }
    return result;
}

int main()
{
    vector<int> A = {1, 2, 3, 4};
    cout << numberOfArithmeticSlices(A);
}
