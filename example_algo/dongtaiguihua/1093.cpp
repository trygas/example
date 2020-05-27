#include "general.h"

/*
 * 构建两个数组
 * dp[i]代表以第i个数据结尾的最长上升子序列的长度
 * ans[i]代表以第i个数据结尾的最长上升子序列的个数
 */
int main(int argc, char *argv[])
{
    vector<int> nums = {2,2,2,2,2};

    int len,max_ans,cnt;
    int dp[2010],ans[2010];
    len=nums.size();
    memset(dp,0,sizeof(dp));
    memset(ans,0,sizeof(ans));
    dp[0]=1;
    max_ans=1;
    ans[0]=1;
    for (int i=1; i<len; i++)
    {
        dp[i]=1;
        ans[i]=1;
        for (int j=0; j<i; j++)
            if (nums[j]<nums[i] && dp[j]+1>dp[i])
            {
                dp[i]=dp[j]+1;
                ans[i]=ans[j];
            }
            else  if (nums[j]<nums[i] && dp[j]+1==dp[i])
            {
                ans[i]+=ans[j];
            }
        if (dp[i]>max_ans)
        {
            max_ans=dp[i];
        }
    }
    cnt=0;
    for (int i=0; i<len; i++)
        if (dp[i]==max_ans) cnt+=ans[i];

    cout << cnt;
}

