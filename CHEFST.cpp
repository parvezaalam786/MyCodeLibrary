#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n"

int main()
{
  fast_io;
  ll T,n1,n2,ans,m;
  cin>>T;
  while(T--){
    cin>>n1>>n2>>m;
    ll ans = max(n1+n2-m*(m+1),abs(n1-n2));
    cout<<ans<<endl;
  }
  return 0;
}