#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll unsigned long long int
#define endl "\n"
int setbits(int N){
  int ans = 0;
  while(N){
    if(N&1)
      ans++;
    N = N>>1;
  }
  return ans;
}

int main()
{
  fast_io;
  int T,N;
  cin>>T;
  while(T--){
    cin>>N;
    int ans = 0;
    while(N>=2048){
      N -=2048;
      ans++;
    }
    ans += setbits(N);
    cout<<ans<<endl;;
  }
  return 0;
}
