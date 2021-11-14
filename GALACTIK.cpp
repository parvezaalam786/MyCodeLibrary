#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

ll cost[100010];
bool visited[100010];
ll mini;
vector<ll> v1[100010];

void dfs(ll src){
    visited[src] = true;
    if(cost[src]>=0&&cost[src]<mini){
        mini = cost[src];
    }
    for(ll i:v1[src]){
        if(!visited[i]){
            dfs(i);
        }
    }
}


int main()
{
   // freopen("Test.txt","r",stdin);
    fast_io;
    ll N,M,C,A,B;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>A>>B;
        v1[A].push_back(B);
        v1[B].push_back(A);
    }
    for(int i=1;i<=N;i++){
        cin>>cost[i];
        visited[i] = false;
    }
    vector<ll> ans;
    int not_connected = 0;
    for(int i=1;i<=N;i++){
        if(!visited[i]){
            mini = INT_MAX;
            dfs(i);
            if(mini==INT_MAX){
                not_connected = 1;
            }
            ans.push_back(mini);
        }
    }
    
    if(ans.size()==1)
        cout<<"0"<<endl;
    else if(not_connected)
            cout<<"-1"<<endl;
    else{
        ll sum = 0;
        sort(ans.begin(),ans.end());
        for(int i=1;i<ans.size();i++){
            sum+=(ans[0]+ans[i]);
        }
        cout<<sum<<endl;
    }        
    return 0;
}
