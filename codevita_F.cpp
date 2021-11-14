/*
Chase excellence, rating will come automatically.
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf 1e9
#define mod 1000000007
#define ff first
#define ss second
bool check(string s1)
{
	int i = 0, j = s1.length() - 1;

	while (i < j)
	{
		if (s1[i] == s1[j])
		{
			i++;
			j--;
		}
		else
			return false;
	}
	return true;
}
void solve()
{
	string s1;
	cin >> s1;
	int n = s1.length();

	bool found = false;
	for (int i = 1; i <= n - 1; i++)
	{
		string temp1 = s1.substr(0, i);

		if (check(temp1))
		{

			for (int j = i + 1; j <= n - 1 - i; j++)
			{
				string temp2 = s1.substr(i, j - i + 1);
				if (check(temp2))
				{
					string temp3 = s1.substr(j + 1);
					if (check(temp3))
					{
						found = true;
						cout << temp1 << "\n" << temp2 << "\n" << temp3;
						break;
					}
				}
			}
			if (found)
				break;
		}
	}
	if (found == false)
		cout << "Impossible";
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
