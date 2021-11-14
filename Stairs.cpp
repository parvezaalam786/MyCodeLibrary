// There are n steps and we can jump max of k steps . Find the number of steps to reach at the top.
#include<bits/stdc++.h>
using namespace std;
int dp[1000];
//Top down approach
int ladderSteps_TD(int n,int k){
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    if(dp[n]!=-1)
        return dp[n];
    int res = 0;
    dp[n] = 0;
    for(int i=1;i<=k;i++){
        dp[n] += ladderSteps_TD(n-i,k);
    }        
    return dp[n];
}
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<=n;i++)
        dp[i] = -1;
    cout<<ladderSteps_TD(n,k)<<endl;

    return 0;
}