#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n"
#define M 1000000007
ll power(ll a,ll b){
    // ll res = 1;
    // x = x%M;
    // while(b>0){
    //     if(b&1){
    //         res = (res*a)%M;
    //     }
    //     b = b>>1;
    //     a = (a*a)%M;
    // }
    // return res;
    ll res;
    if(b==0) return 1;
    res = power(a,b/2);
    res = (res*res)%M;
    if(b&1) res = (res*a)%M;
    return res;
}
int main()
{
    fast_io;
    ll T,N;
    cin>>T;
    while(T--){
        cin>>N;
        N++;
        ll x = N/2;
        ll y = N-x;
        ll ans = (power(2,x)+power(2,y)-2)%M;
        cout<<ans<<endl;
    }
    return 0;
}