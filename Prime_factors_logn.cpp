#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
#define fast_io ios::sync_with_stdio(false);cin.tie(NULL);
#define input freopen("Test.txt","r",stdin)
#define output freopen("Output.txt","w",stdout);
#define what_is(x) cout<<#x<<" is "<<x<<endl;
#define F(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define eb emplace_back
#define inf 1000000000
const double pi = 3.141592653589793238460;
#define debug false
#define mod 1000000007

void prime_factors(int N)
{
    for(int i=2;i*i<=N;i++)
    {
        if(N%i==0)
        {
            int cnt = 0;
            while(N%i==0)
            {
                cnt++;
                N /= i;
            }
            cout<<i<<"^"<<cnt<<"\n";
        }
    }
    if(N>1)
        cout<<N<<"^"<<"1"<<"\n";
}

void solve()
{
    int N; cin>>N;
    prime_factors(N);
}

int main()
{
    // fast_io; // input; // output; // if(debug){watch_is();}
    solve();   
    return 0;
}