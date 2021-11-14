#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

bool visited[100010];
vector<int> adjList[100010];

void dfs(int src){
    visited[src] = true;
    for(auto node:adjList[src]){
        if(!visited[node]){
            dfs(node);
        }
    }
}
int main()
{
    int T,N,e,u,v;
    cin>>T;
    while(T--){
        for(int i=0;i<100010;i++)
            visited[i] = false;
        for(int i=0;i<100010;i++)
            adjList[i].clear(); 
        int ans = 0;
        cin>>N>>e;
        while(e--){
            cin>>u>>v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        for(int i=0;i<N;i++){
            if(!visited[i]){
                dfs(i);
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}