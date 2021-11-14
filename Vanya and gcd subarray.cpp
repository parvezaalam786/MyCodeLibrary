#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int arr[600];
int dp[600][105][105];
int fun(int idx,int check,int gcd,int n)
{
	if(idx == n)
	{
		if(gcd==1)
			return 1;
		return 0;
	}
	if(dp[idx][check][gcd]!=-1)
		return dp[idx][check][gcd];
	int res = 0;

	res = fun(idx+1,check,gcd,n);
	if(res>=mod)
			res -= mod;
	if(arr[idx]>check)
	{
		res += fun(idx+1,arr[idx],__gcd(gcd,arr[idx]),n);
		if(res>=mod)
			res -= mod;
	}

	dp[idx][check][gcd] = res;
	return res;
}


int solve(int n)
{
	memset(dp,-1,sizeof(dp));
	int res = 0;
	for(int i=0;i<n-1;i++)
	{
		res += fun(i+1,arr[i],arr[i],n);
		if(res>=mod)
			res -= mod;
	}
	return res;
}


int main()
{
	int n; cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	int ans = solve(n);
	cout<<ans<<"\n";
	return 0;
}