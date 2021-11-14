#include<bits/stdc++.h>
using namespace std;

int dp[100010];
int fun(int i, string& s1, int n)
{
	if (i >= n)
		return 1;
	if (s1[i] == '0')
		return 0;
	if (dp[i] != -1)
		return dp[i];
	int c1 = 0, c2 = 0;

	if (s1[i] != '0')
	{
		c1 = fun(i + 1, s1, n);
		if (i + 1 < n and ((s1[i] - '0') * 10 + (s1[i + 1] - '0') <= 26))
			c2 += fun(i + 2, s1, n);
	}

	return dp[i] = c1 + c2;
}
int numDecodings(string s1)
{
	int n = s1.length();
	if (n <= 1)
		return n;
	memset(dp, -1, sizeof(dp));
	int ans = fun(0, s1, n);
	return ans;
}

int main()
{
	string s1;
	cin >> s1;
	int n = s1.length();
	int ans = numDecodings(s1);
	cout << ans;
	return 0;
}