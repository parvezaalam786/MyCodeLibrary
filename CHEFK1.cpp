#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define endl "\n"
int main()
{
    // freopen("Test.txt","r",stdin);
    // freopen("Output.txt","w",stdout);
    fast_io;
    ll T,N,M;
    cin>>T;
    while(T--){
        cin>>N>>M;
        ll ans = 0;
        ll check = N*N;
        check += N;
        check = check>>1;
        if(M<N-1||M>check)
            ans = -1;
        else if(N==1&&M==0)
            ans = 0;    
        else if(M==N-1)
            ans = 1;   
        else if(M==1&&N==1)
            ans = 1;     
        else if(M==N || M==N+1)
            ans = 2;
        else if(M>N+1 && M<=2*N)
            ans = 3;
        else{
            ans = 3;
            if(N&1)  // N is odd
            {
                ll low = N/2;
                ll upp = low+1;
                bool turn = true;
                M -= 2*N;
                while(M>0){
                    if(turn){
                       M -= low;
                       turn = false;
                       }
                    else{
                        M -= upp;
                        turn = true;
                    }
                     ans++;
                }
            }
            else{       //even
                ll low = N/2;
                M -= 2*N;
                while(M>0){
                    M -= low;
                    ans++;
                }
            }
        }
        cout<<ans<<endl;            
    }
    return 0;
}