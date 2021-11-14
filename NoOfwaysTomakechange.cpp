#include<bits/stdc++.h>
using namespace std;
#define int long long

int ways(vector<int> &coins,int amt)
{
    int n = coins.size();

    int dp[n+5][amt+5];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=n;i++)
        dp[i][0] = 1;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=amt;j++)
        {
            if(j>=coins[i-1])
            {
                dp[i][j] = dp[i-1][j]+dp[i][j-coins[i-1]];
            }
            else
            {
                dp[i][j] = dp[i-1][j]; 
            }            
        }
    }
    return dp[n][amt];
}

int32_t main()
{
    int n,m;
    cin>>n>>m;
    vector<int> coins(m);
    for(auto &i:coins)
        cin>>i;
    int ans = ways(coins,n);
    cout<<ans<<"\n";
    return 0;
}