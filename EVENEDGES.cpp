#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> adj[100010];
bool visited1[100010],visited2[100010];
int edges = 0;
bool odd_comp_find;

void dfs(int src){
    visited1[src] = true;
    visited2[src] = true;
    edges += adj[src].size();
    for(auto x:adj[src]){
        if(!visited2[x]){
            dfs(x);
        }
    }
    int total = edges/2;
    if(total%2==0||odd_comp_find==true)
        visited1[src] = false;
}

int main(){
    int T,N,M;
    cin>>T;
    while(T--){
        odd_comp_find = false;
        for(int i=0;i<100010;i++){
            adj[i].clear();
            visited1[i] = false;
            visited2[i] = false;
        }            
        cin>>N>>M;
        for(int i=0;i<M;i++){
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        if(M%2==0){
            cout<<"1"<<endl;
            for(int i=0;i<N;i++){
                cout<<"1 ";
            }
            cout<<endl;
        }
        else{
            bool odd = false;
            int oddvalue = -1;
            for(int i=1;i<=N;i++){
                if(adj[i].size()&1){
                    odd = true;
                    oddvalue = i;
                    break;
                }
            }
            if(odd==false){
                edges = 0;
                int s = 0,odd_comp = 0;
                for(int i=1;i<=N;i++){
                    if(!visited2[i]){
                        dfs(i);
                        edges = edges/2;
                        if(edges%2==1){
                            if(s==0)
                                s = i;
                        odd_comp_find = true;
                        odd_comp++;        
                        }
                        edges = 0;
                    }
                }
                if(odd_comp==1){
                    cout<<"3"<<endl;
                    int arr[N+1];
                    for(int i=1;i<=N;i++){
                        if(i==s)
                            arr[i] = 1;
                        else if(i==adj[s][0])
                            arr[i] = 2;
                        else 
                            arr[i] = 3;       
                    }
                    for(int i=1;i<=N;i++)
                        cout<<arr[i]<<" ";
                    cout<<endl;    
                }
                else{
                    cout<<"2"<<endl;
                    int s1 = s,s2 = adj[s][0];
                    int arr[N+1];
                    for(int i=1;i<=N;i++){
                        if(visited1[i]){
                            if(i!=s1&&i!=s2)
                                arr[i] = 1;
                            else 
                                arr[i] = 2;   
                        }
                        else
                            arr[i] = 2;
                    }
                    for(int i=1;i<=N;i++)
                        cout<<arr[i]<<" ";
                    cout<<endl;
                }
            }
            else{
                cout<<"2"<<endl;
                int arr[N+1];
                for(int i=1;i<=N;i++){
                    if(i==oddvalue)
                        arr[i] = 2;
                    else
                        arr[i] = 1;    
                }
                for(int i=1;i<=N;i++)
                    cout<<arr[i]<<" ";
                cout<<endl;
            }
        }
    }
    return 0;
}