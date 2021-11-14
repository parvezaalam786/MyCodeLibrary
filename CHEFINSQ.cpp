#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define endl "\n"
// ll bC(ll n, ll k){    
//     if (k == 0 || k == n)  
//         return 1;    
//     return bC(n - 1, k - 1) +  
//                 bC(n - 1, k);  
// }  
ll min(ll a, ll b) 
{ 
    return (a < b) ? a : b; 
}  
ll bC(ll n, ll k) 
{ 
    ll C[n + 1][k + 1]; 
    ll i, j;  
    for (i = 0; i <= n; i++) 
    { 
        for (j = 0; j <= min(i, k); j++) 
        { 
            if (j == 0 || j == i) 
                C[i][j] = 1;  
            else
                C[i][j] = C[i - 1][j - 1] + 
                          C[i - 1][j]; 
        } 
    } 
  
    return C[n][k]; 
} 

int main()
{
  fast_io;
  int T,N,K;
  cin>>T;
  while(T--){
    cin>>N>>K;
    int arr[N];
    map<int,int> m1;
    pair<int,int> p1;
    for(int i=0;i<N;i++){
      cin>>arr[i];
    }
    sort(arr,arr+N);
    int k_arr[K];
    for(int i=0;i<K;i++){
      k_arr[i] = arr[i];
    }
    for(int i=0;i<N;i++){
      if(m1.find(arr[i])!=m1.end()){
        auto it1 = m1.find(arr[i]);
        it1->second += 1;
      }
      else{
        p1 = make_pair(arr[i],1);
        m1.insert(p1);
      }
    }
      ll ans = 1;
      for(int i=0;i<K;i++){
        int c = 0;
        int x = k_arr[i];
        for(int j=i;j<K;j++){
          if(x!=-1 && k_arr[j]==x){
            c++;k_arr[j] = -1;
          }
        }

        if(x==-1)
          continue;
        auto it1 = m1.find(x);
        ll n = it1->second;
        ll ncr = bC(n,c);
        ans *= ncr; 
      }
      cout<<ans<<endl;
    }
  return 0;
}