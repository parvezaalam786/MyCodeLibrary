#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define endl "\n"
#define mod 1000000007
int main()
{
    //fast_io;
    ll N,K;
    ll sum = 0;
    cin>>N>>K;
    ll arr[N];
    for(ll i=0;i<N;i++) cin>>arr[i];
    //sort(arr,arr+N);
    map<ll,ll> m1;
    pair<ll,ll> p1;
    for(ll i=0;i<N;i++){
        ll x = arr[i];
        if(m1.find(x)!=m1.end()){
            auto it1 = m1.find(x);
            it1->second += 1;
        }
        else{
            p1 = make_pair(x,1);
            m1.insert(p1);
        }
    }
    ll n = m1.size();
    ll index = 0;
    ll freq[n+10] = {0};
    for(int i=0;i<n+10;i++) freq[i] = 0;
    for(auto it1 = m1.begin();it1!=m1.end();it1++){
        freq[index] = it1->second;
        index++;
    }
    //for(int i=0;i<index;i++) cout<<freq[i]<<" ";
    n = index;
    K = min(n,K);
    ll dp[K][n];

    for(ll i=0;i<K;i++){
        for(ll j=0;j<n;j++)
            dp[i][j] = 0;
    }

    for(ll i=0;i<n;i++){
        dp[0][i] = freq[i];
    }

    for(ll l = 1;l<K;l++){
        for(ll i=0;i<n;i++){
             sum = 0;
            for(ll j=i+1;j<n-l+1;j++){
                sum =(sum%mod+dp[l-1][j]%mod)%mod;
            }
            dp[l][i] = ((dp[0][i]%mod)*(sum%mod))%mod;
        }
    }
    unsigned ll ans = 1;
    for(ll i=0;i<K;i++){
        for(ll j=0;j<n;j++){
            //cout<<dp[i][j]<<"  ";
            ans = (ans + dp[i][j])%mod;
        }
        //cout<<endl;
    }
    //ans = (ans+1)%mod;
    cout<<ans<<endl;
    return 0;
}