#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define endl "\n"

ll expo(ll a,ll b,ll mod){
    if(a==1||b==0) return 1;
    ll res = 1;
    while(b>0){
        if(b&1) res = (res*a)%mod;
        b = b>>1;
        a = (a*a)%mod;
    }
    return res;
}
ll primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int main(){
    
    fast_io;
    // freopen("Test.txt","r",stdin);
    // freopen("Output.txt","w",stdout);
    ll N,T;
    cin>>N;
    ll arr[N];
    for(ll i=0;i<N;i++) cin>>arr[i];
    ll tables[N][25];
    for(ll i=0;i<N;i++){
        for(ll j=0;j<25;j++){
            tables[i][j] = 0;
        }
    }
    for(ll i=0;i<N;i++){
        ll a = arr[i];
        for(ll j=0;j<25;j++){
            ll cnt = 0;
            while(a%primes[j]==0){
                cnt++;
                a /= primes[j];
                //if(a==0) break;
            }
            tables[i][j] = cnt;
        }
    }
    //Cumulative frequency
    
    for(ll i=1;i<N;i++){
        for(ll j=0;j<25;j++){
            tables[i][j] += tables[i-1][j];
        }
    }
    cin>>T;
    ll a,b,mod,ans = 1,x,l,r;
    while(T--){
        ans = 1;
        cin>>a>>b>>mod;
        a-=1;
        b-=1;
        for(ll i=0;i<25;i++){
            if(a) l = tables[b][i] - tables[a-1][i];
            else l = tables[b][i];
            r = expo(primes[i],l,mod);
            ans = (ans*r)%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}