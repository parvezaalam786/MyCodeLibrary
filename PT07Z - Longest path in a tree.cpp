#include<bits/stdc++.h>
using namespace std;
bool visited[10010];
int dist[10010];
vector<int> adjList[10010];
void dfs(int src){
    visited[src] = true;
    for(int i:adjList[src]){
        if(!visited[i]){
            dist[i] += (dist[src]+1);
            dfs(i);
        }
    }
}
int main()
{
    int N;
    cin>>N;
    for(int i=0;i<10010;i++){
        visited[i] = false;
        dist[i] = 0;
    }
    for(int i=0;i<N-1;i++){
        int x,y;
        cin>>x>>y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    dfs(1);
    int x = max_element(dist,dist+10010) - dist;
    for(int i=0;i<10010;i++){
        visited[i] = false;
        dist[i] = 0;
    }
    dfs(x);
    cout<<*(max_element(dist,dist+10010))<<endl;
    return 0;
}