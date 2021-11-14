#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define int long long
#define endl "\n"
#define what_is(x) cout<<#x<<" is "<<x<<endl;
#define F(i,a,b) for(int i = a; i < b; i++)
#define MAX(a,b,c) max(a,max(b,c))
#define MIN(a,b,c) min(a,min(b,c))
#define pb push_back
#define eb emplace_back
#define inf 1e18
const double pi = 3.141592653589793238460;
#define debug false
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define mod 1000000007
const int maxn = 100010;

/*
int dfs(int src, int par, int d)
{
    int mx1 = 0, mx2 = 0;
    depth[src] = d;
    for (auto i : adj[src])
    {
        if (i == par)
            continue;
        int temp = dfs(i, src, d + 1) + 1;
        if (temp >= mx1)
        {
            mx2 = mx1;
            mx1 = temp;
        }
        else if (temp > mx2)
            mx2 = temp;
    }
    dia = max(dia, mx1 + mx2);
    return mx1;
}
*/

bool visited[maxn];
int dist[maxn];
vector<int> adjList[maxn];

void dfs(int src)
{
	visited[src] = true;
	for (int i : adjList[src])
	{
		if (!visited[i])
		{
			dist[i] = dist[src] + 1;
			dfs(i);
		}
	}
}

void solve()
{
	int n;
	cin >> n;
	for (int i = 0; i < maxn; i++)
	{
		visited[i] = false;
		dist[i] = 0;
	}
	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		adjList[x].push_back(y);
		adjList[y].push_back(x);
	}
	dfs(1);
	int x = max_element(dist, dist + n) - dist;
	F(i, 0, maxn)
	{
		visited[i] = false;
		dist[i] = 0;
	}
	dfs(x);
	cout << *(max_element(dist, dist + n + 1)) << "\n";
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif

	// if(debug){watch_is();}
	solve();
	return 0;
}