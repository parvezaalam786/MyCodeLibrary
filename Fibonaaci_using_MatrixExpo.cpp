#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
#define mod 1000000007

void multiply(ll F[2][2],ll M[2][2])
{
    ll a = ((F[0][0]*M[0][0])%mod+(F[0][1]*M[1][0])%mod)%mod;
    ll b = ((F[0][0]*M[0][1])%mod+(F[0][1]*M[1][1])%mod)%mod;
    ll c = ((F[1][0]*M[0][0])%mod+(F[1][1]*M[1][0])%mod)%mod;
    ll d = ((F[1][0]*M[0][1])%mod+(F[1][1]*M[1][1])%mod)%mod;

    F[0][0] = a;
    F[0][1] = b;
    F[1][0] = c;
    F[1][1] = d;
}
void power(ll F[2][2],ll n)
{
    if(n==0||n==1)
        return;
    ll M[2][2] = {{1,1},{1,0}};    
    power(F,n/2);
    multiply(F,F);
    if(n&1)
        multiply(F,M);
}
ll fib(ll n)
{
    ll F[2][2] = {{1,1},{1,0}};
    if(n==0)
        return 0;
        power(F,n-1);
        return F[0][0];
}

int main()
{
    ll T,n;
    cin>>T;
    while(T--){
        cin>>n;
        if(n==0) cout<<"0\n";
        else if(n==1) cout<<"2\n";
        else cout<<fib(n+3)%mod<<endl;
    }
    return 0;
}