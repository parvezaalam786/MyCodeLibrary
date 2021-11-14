#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define mp make_pair
#define endl "\n"
#define tab " "
#define pb push_back
#define ff first
#define ss second
#define watch(x) cout<<(#x)<<" = "<<x<<" "
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pll pair<ll,ll>
#define pi 3.141592653589793238460

//using namespace std;

int main()
{
  // fast;
  ll n,k;
  cin>>n>>k;

  ll frq[8005];
  for(int i=0;i<8005;i++) frq[i]=0;

  ll ele;
  for(int i=0;i<n;i++) 
  {
    cin>>ele;
    frq[ele]+=1;
  }

  vector<ll> v;

  for(int i=0;i<8005;i++)
  {
    if(frq[i]!=0) v.push_back(frq[i]);
  }

  // for(int i=0;i<v.size();i++)
    // cout<<v[i]<<" ";

  // now vector v has frequency of all the elements
  ll len=v.size();

  int row = min(len,k);
  
  ll dp[row][len];

  for(int i=0;i<row;i++)
    for(int j=0;j<len;j++)
      dp[i][j]=0;

  for(int i=0;i<len;i++)
      dp[0][i]=v[i];

    ll sum=0;

  for(int i=1;i<row;i++)
  {
    for(int j=0;j<len;j++)
    { 
      sum = 0;
      for(int x=j+1;x<len-i+1;x++)
        sum = (sum % mod + dp[i-1][x] % mod)%mod;

      dp[i][j] = ((dp[0][j] % mod)*(sum % mod))%mod;
    }
  }

  ll ans = 1;
  for(int i=0;i<row;i++)
    for(int j=0;j<len;j++)
      ans = ((ans ) + (dp[i][j] ))%mod;

  // for(int i=0;i<row;i++)
  //   for(int j=0;j<len;j++){
  //     cout<<dp[i][j]<<tab;
  //     if(j==len-1)
  //       cout<<endl;
  //   }

    cout<<ans<<endl;

  




  return 0;
}