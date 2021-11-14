#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf 1e9
#define mod 1000000007
#define ff first
#define ss second

void computeLPS(string &pat, int lps[])
{
	int m = pat.length();
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while (i < m)
	{
		if (pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len != 0)
			{
				len = lps[len - 1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMPSearch(string pat, string txt)
{
	int m = pat.length();
	int n = txt.length();

	int lps[m];
	computeLPS(pat, lps);
	int i = 0, j = 0;
	while (i < n)
	{
		if (pat[j] == txt[i])
		{
			i++;
			j++;
		}
		if (j == m)
		{
			cout << "found at :" << (i - j) << "\n";
			j = lps[j - 1];
		}
		else if (i < n and pat[j] != txt[i])
		{
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}

void solve()
{
	string txt = "AAAAABAAABA";
	string pat = "AAAA";
	KMPSearch(pat, txt);
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
