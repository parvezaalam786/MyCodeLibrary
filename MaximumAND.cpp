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


void solve()
{
	int n;
    cin>>n;
    vector<int> arr(n);
    F(i,0,n) cin>>arr[i];
    int res = 0;
    for(int j=31;j>=0;j--)
    {
        vector<int> temp;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]&(1<<j))
            {
                temp.push_back(arr[i]);
            }
        }
        if(temp.size()>=2)
        {
            res += (1<<j);
            arr = temp;
        }
    }
    cout<<res<<"\n";

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