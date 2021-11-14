/*
Chase excellence, rating will come automatically.
*/
#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define ll long long
#define pb push_back
#define inf 1e9
#define mod 1000000007
#define ff first
#define ss second

ll greatesfactor(ll n)
{
	set<ll> fact;
	for (ll i = 1; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			if (i * i == n)
				fact.insert(i);
			else
			{
				fact.insert(i);
				fact.insert(n / i);
			}
		}
	}
	fact.erase(fact.find(n));
	return *(--fact.end());
}
void solve()
{
	ll a, b;
	cin >> a >> b;

	ll x = a;
	vector<ll> v1, v2;
	v1.push_back(x);
	while (x != 1)
	{
		x = greatesfactor(x);
		v1.push_back(x);
	}
	x = b;
	v2.push_back(x);
	while (x != 1)
	{
		x = greatesfactor(x);
		v2.push_back(x);
	}

	// for (auto i : v1)
	// 	cout << i << " ";
	// cout << "\n";
	// for (auto i : v2)
	// 	cout << i << " ";
	// cout << "\n";

	ll ans = inf;
	for (int i = 0; i < v1.size(); i++)
	{
		for (int j = 0; j < v2.size(); j++)
		{
			if (v1[i] == v2[j])
			{
				ans = min(ans, i * 1LL + j * 1LL);
			}
		}
	}
	cout << ans << "\n";
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
