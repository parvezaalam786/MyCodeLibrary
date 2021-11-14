#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll unsigned long long int
#define endl "\n"

ll ans[] = {0,1,1,2,3,5,8,3,1,4,5,9,4,3,7,0,7,7,4,1,5,6,1,7,8,5,3,8,1,9,0,9,9,8,7,5,2,7,9,6,5,1,6,7,3,0,3,3,6,9,5,4,9,3,2,5,7,2,9,1};
ll power(ll x, ll y) 
{ 

    ll temp ;       
    if(y==0) return 1;
    temp = power(x,y/2);
    if(y&1) return x*temp*temp;
    else return temp*temp; 
}
ll digit(ll N){
    ll level = 0;
    while(N)
    {
        N=N>>1;
        level++;
    }
    ll a = power(2,level-1);
    if(a==1)
        return 0;
    ll index = a%60;
    
    return ans[index-1];
}
int main()
{
    fast_io;
    //freopen("Test.txt","r",stdin);
    //freopen("Output.txt","w",stdout);
    ll T,N;
    cin>>T;
    while(T--){
        cin>>N;
        ll ans1 = digit(N);
        cout<<ans1<<endl;
    }
    return 0;   
}