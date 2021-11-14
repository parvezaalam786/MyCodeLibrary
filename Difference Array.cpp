#include<bits/stdc++.h>
using namespace std;
void DiffArray(int A[],int D[],int n){
    D[0] = A[0];
    D[n] = 0;
    for(int i=1;i<n;i++){
        D[i] = A[i] - A[i-1];
    }
}
void update(int D[],int l,int r,int x,int n){
    if(l<0){
        l=0;
    }
    if(r>=n){
        r = n-1;
    }
    D[l]+=x;
    D[r+1]-=x;
}
void Construct(int A[],int D[],int n){
    for(int i=0;i<n;i++){
        if(i==0){
            A[i] = D[i];
        }
        else{
            A[i] = D[i] + A[i-1];
        }
    }
}
int main(){
    //freopen("Test.txt","r",stdin);
    int n,T;
    cin>>T;
    while(T--){
        cin>>n;
        int A[n]={0},B[n]={0},C[n]={0},D[n+1]={0};
        for(int i=0;i<n;i++){
            cin>>B[i];
        }
        for(int i=0;i<n;i++){
            cin>>C[i];
        }
        DiffArray(A,D,n);
        for(int i=1;i<=n;i++){
            int x = i-B[i-1]-1;
            int y = i+B[i-1]-1;
            update(D,x,y,1,n);
        }
        Construct(A,D,n);
        sort(A,A+n);
        sort(C,C+n);
        int flag = 0;
        for(int i=0;i<n;i++){
            if(A[i]!=C[i]){
                flag = 1;
                break;
            }
        }
        if(flag==1){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
    return 0;
}