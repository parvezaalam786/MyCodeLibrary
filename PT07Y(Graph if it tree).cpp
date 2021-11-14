#include<bits/stdc++.h>
using namespace std;
vector<int> adjList[10010];
bool visited[10010];
int N,M;

bool isCyclic(int v,int parent)
{
    visited[v] = true;
    for(int i:adjList[v]){
        if(!visited[i]){
            if(isCyclic(i,v))
                return true;
        }
        else if(i!=parent)
            return true;
    }
    return false;
}
bool isTree()
{
    for(int i=1;i<=N;i++)
        visited[i] = false;
    if(isCyclic(1,-1))
        return false;
    for(int u=1;u<=N;u++)
    {
        if(!visited[u])
            return false;
    }
    return true;       
}

int main()
{
    //freopen("Test.txt","r",stdin);
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    bool Tree = isTree();
    if(Tree)
        cout<<"YES"<<endl;
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}