#include "general.h"

int main()
{
    string  s = "11111878787676172120121101212918291829819";

    int size = s.size();
    if (size <= 0) {
        return 0;
    }
    vector<int> dp(size + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= size; i++) {
        if (s[i - 1] == '0') {
            dp[i] = 0;
        }
        else {
            dp[i] += dp[i - 1];
        }
        if (i > 1) {
            int num = atoi(s.substr(i - 2, 2).c_str());
            if (num >= 10 && num <= 26) {
                dp[i] += dp[i - 2];
            }
        }
    }

    PrintVector(dp);
}
