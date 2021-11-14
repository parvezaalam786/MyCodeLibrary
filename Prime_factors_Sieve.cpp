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

int factor[1000001];
void sieve()
{
    int maxN = 1000001;
    factor[1] = 1;
    F(i,2,maxN)
    {
        factor[i] = i;
    }
    for(int i=4;i<maxN;i+=2)
    {
        factor[i] = 2;
    }
    for(int i=3;i*i<maxN;i++)
    {

    }
}
void solve()
{

}

int main()
{
    // fast_io; // input; // output; // if(debug){watch_is();}
    solve();   
    return 0;
}