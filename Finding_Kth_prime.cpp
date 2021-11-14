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

const int N = 90000001;
bool prime[N];
vector<int> primes(N);
void generate_primes()
{
    for(int i=0;i<N;i++)
        prime[i] = true;
    prime[0] = prime[1] = false;
    for(int i=2;i*i<=N;i++)
    {
        if(prime[i])
        {
            for(int j=i*i;j<=N;j+=i)
            {
                prime[j] = false;
            }
        }
    }
    for(int i=2;i<N;i++)
    {
        if(prime[i])
            primes.pb(i);
    }
}
void solve()
{
    primes.pb(-1);
    generate_primes();
    // for(int i=0;i<10;i++)
    //     cout<<primes[i]<<" ";
    int T;
    cin>>T;
    while(T--)
    {
        int n; cin>>n;
        cout<<primes[n]<<"\n";
    }
}

int main()
{
    // fast_io; // input; // output; // if(debug){watch_is();}
    solve();   
    return 0;
}