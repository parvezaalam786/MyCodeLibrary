#include<bits/stdc++.h>
using namespace std;
bool visited[10010];
int mod = 1000000007;
vector<int> adjList[10010];
int ways[10010];
void dfs(int src,int dest)
{
    if(src==dest)
        ways[src] = 1;
    visited[src] = true;
    for(int i:adjList[src]){
        if(!visited[i])
        {
            if(i==dest)
            {
                ways[i] = 1;  
            }
            dfs(i,dest);           
        }
        ways[src] += ways[i]; 
        ways[src] %= mod;               
    }
}
int main()
{
   // freopen("Test.txt","r",stdin);
    int D,C,B,S,T;
    cin>>D;
    while(D--)
    {
        cin>>C>>B>>S>>T;
        for(int i=0;i<10010;i++)
        {
            visited[i] = false;
            adjList[i].clear();
        }
        for(int i=0;i<10010;i++)
            ways[i] = 0;
        for(int i=1;i<=B;i++)
        {
            int x,y;
            cin>>x>>y;
            adjList[x].push_back(y);
        }
        dfs(S,T);
        // for(int i=1;i<=C;i++)
        //     cout<<ways[i]<<", ";
        cout<<ways[S]<<endl;        
    }
    return 0;
}