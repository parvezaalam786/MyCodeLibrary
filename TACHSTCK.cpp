#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll unsigned long long int
#define endl "\n"

int main()
{
  fast_io;
 ll N,D;
 cin>>N>>D;
 ll arr[N];
 for(ll i=0;i<N;i++) cin>>arr[i];
 sort(arr,arr+N);
 ll ans = 0;
 for(ll i=0;i<N;i++){
   if(arr[i+1]-arr[i]<=D){
     ans++;i++;
   }
 } 
 cout<<ans<<endl;
 return 0;
}