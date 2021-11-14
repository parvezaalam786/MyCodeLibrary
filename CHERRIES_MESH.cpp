//https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050edb/0000000000170721
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int count1 = 0;
bool visited[100010];
vector<int> adjList[100010];
int dfs(int src){
    visited[src] = true;
    for(int i:adjList[src]){
        if(!visited[i]){
            count1++;
            dfs(i);
        }
    }
    return count1;
}

int main()
{
    //freopen("Test.txt","r",stdin);
    fast_io;
    int N,M,T,c=0;
    cin>>T;
    while(T--){  
        c++;      
        cin>>N>>M;
        for(int i=1;i<=N;i++){
            adjList[i].clear();
            visited[i] = false;
        }
        for(int i=0;i<M;i++){
            int u,v;
            cin>>u>>v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        ll ans = 0,cnt=0;
        for(int i=1;i<=N;i++){
            if(!visited[i]){
                cnt++;
                count1 = 0;
                ans += dfs(i);
            }
        }
        ans += (cnt-1)*2;
        cout<<"Case #"<<c<<": "<<ans<<endl;
    }
    return 0;
}