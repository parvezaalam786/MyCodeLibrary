#include<bits/stdc++.h>
using namespace std;

int climbStairs(int n)
{
	int dp[n + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

int main()
{
	int n;
	cin >> n;
	int ans = climbStairs(n);
	cout << ans;
	return 0;
}