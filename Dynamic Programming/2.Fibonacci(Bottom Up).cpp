#include<bits/stdc++.h>
using namespace std;
int fib(int n){
    int dp[1000] = {};
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    int ans = fib(n);
    cout<<n<<"th fib "<<ans<<endl;
    return 0;
}