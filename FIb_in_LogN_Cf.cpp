// https://codeforces.com/blog/entry/14516

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

map<ll,ll> F;
ll f(ll n){
    if(F.count(n)) return F[n];
    ll k = n/2;
    if(n%2==0){
        return F[n] = (f(k)*f(k)+f(k-1)*f(k-1))%mod;
    }
    else{
        return F[n] = (f(k)*f(k+1)+f(k-1)*f(k))%mod;
    }
}
int main()
{
    F[0] = F[1] = 1;
    int n;
    cin>>n;
    cout<<(n==0?0:f(n-1))<<endl;   
    return 0;
}