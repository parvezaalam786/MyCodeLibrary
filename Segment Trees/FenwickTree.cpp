#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
#define fast_io ios::sync_with_stdio(false);cin.tie(NULL);
#define input freopen("Test.txt","r",stdin)
#define output freopen("Output.txt","w",stdout);
#define what_is(x) cout<<#x<<" is "<<x<<endl;
#define F(i,a,b) for(int i = a; i < b; i++)
#define MAX(a,b,c) max(a,max(b,c))
#define MIN(a,b,c) min(a,min(b,c))
#define pb push_back
#define eb emplace_back
#define inf 1000000000
const double pi = 3.141592653589793238460;
#define debug false
#define mod 1000000007

int arr[100010];
int BIT[100010] = {0};

// Range sum update - logn time
void update(int i,int inc,int N)
{
    while(i<=N)
    {
        BIT[i] += inc;
        i = i+(i&(-i));
    }
}
// Sum till ith index  - logn time
int query(int i)
{
    int ans = 0;
    while(i>0)
    {
        ans += BIT[i];
        i -= (i&(-i));
    }
    return ans;
}

void solve()
{
    int n; cin>>n;
    F(i,1,n+1)
    {
        cin>>arr[i];
        update(i,arr[i],n);
    }
    int q,l,r;
    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        cout<<query(r)-query(l-1)<<"\n";
    } 
}

int main()
{
     // input; // output; // if(debug){watch_is();}
    fast_io;
    solve();   
    return 0;
}