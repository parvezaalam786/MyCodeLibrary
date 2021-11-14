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
#define inf 1e9
const double pi = 3.141592653589793238460;
#define debug false
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define mod 1000000007 

int ans = 0,DONE = (1<<4)-1;

void solve(int rowMask,int ld,int rd)
{
    if(rowMask==DONE)
    {
        ans++;
        return;
    }
    int safe = DONE&(~(rowMask|ld|rd));  
    while(safe)
    {
        int p = safe&(-safe);
        safe = safe-p;
        solve(rowMask|p,(ld|p)<<1,(rd|p)>>1);
    }    
}

int32_t main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    // #ifndef ONLINE_JUDGE
        // freopen("Test.txt","r",stdin);
        // freopen("Output.txt","w",stdout);
    // #endif
    
     // if(debug){watch_is();}
    solve(0,0,0);   
    cout<<ans<<"\n";
    return 0;
}