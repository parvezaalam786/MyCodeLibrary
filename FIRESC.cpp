#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n"

int cnt_nodes = 0;
long long int ans = 0;

bool visited[100010];
vector<int> v1[100010];

void dfs(int src){
    visited[src] = true;
    cnt_nodes++;
    for(int i=0;i<v1[src].size();i++){
        if(!visited[v1[src][i]]){
            dfs(v1[src][i]);
        }
    }
    return ;
}
int main(){
    //freopen("Test.txt","r",stdin);
    fast_io;
    int N,M,T;
    cin>>T;
    while(T--){
        cin>>N>>M;
        for(int i=0;i<N;i++){
            visited[i] = false;
        }
        for(int i=0;i<N;i++){
            v1[i].clear();
        }
        for(int i=0;i<M;i++){
            int a,b;
            cin>>a>>b;
            a--;b--;
            v1[a].push_back(b);
            v1[b].push_back(a);
        }
        int components = 0;ans = 1;
        for(int i=0;i<N;i++){
            if(!visited[i]){
                cnt_nodes = 0;
                components++;
                dfs(i);
                ans = (ans*cnt_nodes)%mod;
            }
        }
        cout<<components<<" "<<ans<<endl;
    }
    return 0;
}

