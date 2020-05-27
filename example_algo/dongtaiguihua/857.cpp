#include "general.h"

int main()
{
    string S = "spbmtkwqpftyahhnughzxscpavtqymtbanjyybdlhbphfrycpytsgzoeunvxaxuwbmecthomrjgmbvaoyjxxefmtxaxgwswdjdjlkpzsuirbujvhesfzdklgkulkmfnlofytaszwtxacnffvszmobxwmlhaxporskwzrvgmdpneggxqidqsdgvcprcnkdrxtsktibilbtggpazwuddhrgsmaspelglhausmfnyksdfyrwtpftrgtw", T = "asgvamuyus";

    int ns = S.size(), nt = T.size();
    vector<vector<int > > dp(nt + 1, vector<int>(ns + 1, 0));
    for(int i = 0; i <= ns; ++i){
        dp[0][i] = i + 1;
    }

    for(int i = 1; i <= nt; ++i){
        for(int j = 1; j <= ns; ++j){
            if (T[i - 1] == S[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i][j - 1];
        }
    }

    int start = 0, len = ns + 1;
    for(int j = 1; j <= ns; ++j){
        if (dp[nt][j] != 0){
            if (j - dp[nt][j] + 1 < len){
                start = dp[nt][j] - 1;
                len = j - dp[nt][j] + 1;
            }
        }
    }

    if (len == ns + 1)
        return 0;
    else
        cout << S.substr(start, len);
    PrintVectorVector(dp);
}
