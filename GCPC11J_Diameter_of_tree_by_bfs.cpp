#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n"
ll dist[100010];
bool visited[100010];
vector<ll> adjList[100010];
ll ans;
ll bfs(ll x){
    queue<ll> q;
    q.push(x);
    for(ll i=0;i<100010;i++){
        visited[i] = false;
        dist[i] = 0;
    }
    visited[x] = true;
    while(!q.empty()){
        x = q.front();
        q.pop();
        for(auto i:adjList[x]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
                dist[i] = dist[x]+1;
            }
        }
    }
    ll leaf_index = max_element(dist,dist+100010) - dist;
    ans = dist[leaf_index];
    return leaf_index;
}


int main()
{
    //freopen("Test.txt","r",stdin);
    fast_io;
    ll T,n;
    cin>>T;
    while(T--){
        cin>>n;
        for(ll i=0;i<n-1;i++){
            ll u,v;
            cin>>u>>v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        bfs(bfs(1));
        cout<<(ans+1)/2<<endl;
        for(ll i=0;i<=n;i++){
            adjList[i].clear();
        }        
    }
    return 0;
}