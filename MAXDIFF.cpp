#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n"

int main()
{
  fast_io;
  //freopen("Test.txt","r",stdin);
  int T,N,K;
  cin>>T;
  while(T--){
    cin>>N>>K;
    int arr[N];
    for(int i=0;i<N;i++) cin>>arr[i];
    sort(arr,arr+N);
    int sum1=0;
    K = min(K,N-K);
    for(int i=0;i<K;i++) sum1-=arr[i];
    for(int i=K;i<N;i++) sum1+=arr[i];
    cout<<sum1<<endl;  
   }
  return 0;
}