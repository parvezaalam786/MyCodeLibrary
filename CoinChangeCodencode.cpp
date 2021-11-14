#include<bits/stdc++.h>
using namespace std;
int coinChange(vector<int>& coins, int amount)
{
    int dp[amount+1];
    int inf = 1000000000;
    dp[0] = 0;
    for(int i=1;i<=amount;i++)
        dp[i] = inf;
    
    int n = coins.size();
    for(int i=1;i<=amount;i++)
    {   
        int ans = inf;
        for(int j=0;j<n;j++)
        {
            if(i-coins[j]>=0)
                ans = min(ans,dp[i-coins[j]]);
        }
        if(ans == inf)
            dp[i] = inf;
        else
            dp[i] = ans+1;
    }        
    if(dp[amount]==inf)
        return -1;
    return dp[amount];
}
int main()
{
    vector<int> coins = {2};
    int amount = 3;
    int ans = coinChange(coins,amount);
    cout<<ans<<"\n";
    return 0;
}