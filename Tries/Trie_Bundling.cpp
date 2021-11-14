#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int N = 1e5 + 5;

typedef struct data
{
	data* child[26];
	int cnt = 0;
} trie;

trie* root;
int n, k;
string a[N];

void insert(string &s)
{
	trie* cur = root;
	for (int i = 0; i < s.size(); i++)
	{
		char ch = s[i];
		int reqd = ch - 'A';
		if (!cur->child[reqd]) //checking if the ith child of the current node exists
			cur->child[reqd] = new trie();
		cur = cur->child[reqd];
	}
	cur->cnt++;
}

int ans = 0;
void dfs(trie* cur, int lvl)
{
	for (int i = 0; i <= 25; i++)
	{
		if (cur->child[i]) //checking if the ith child of the current node exists
		{
			dfs(cur->child[i], lvl + 1);
			cur->cnt += cur->child[i]->cnt;
		}
	}
	while (cur->cnt >= k) //If my cuurent node has>= K active words
	{
		cur->cnt -= k;
		ans += lvl;
	}
}

int32_t main()
{
	IOS;
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		root = new trie();
		ans = 0;
		cin >> n >> k;
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
			insert(a[i]);
		}
		dfs(root, 0);
		cout << "Case #" << tc << ": " << ans << "\n";
	}
	return 0;
}