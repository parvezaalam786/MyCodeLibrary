#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast_io ios::sync_with_stdio(false);cin.tie(NULL);
#define input freopen("Test.txt","r",stdin)
#define output freopen("Output.txt","w",stdout);
#define what_is(x) cout<<#x<<" is "<<x<<endl;
#define pi 2*acos(0.0)
#define pb push_back
#define eb emplace_back

int arr[10000007];
int main()
{
    fast_io;
    int n,m; cin>>n>>m;
    memset(arr,0,sizeof(arr));
    for(int i=0;i<m;i++)
    {
        int a,b,k; cin>>a>>b>>k;
        arr[a-1] += k;
        arr[b] -= k;
    }
    for(int i=1;i<n;i++)
    {
        arr[i] = arr[i]+arr[i-1];
    }
    int ans = *max_element(arr,arr+n);
    cout<<ans<<endl;
    
    return 0;
}