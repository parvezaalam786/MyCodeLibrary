#include<bits/stdc++.h>
using namespace std;
int query(int *blocks,int *arr,int L,int R,int rn){
    int ans = 0;
    //Left part
    while(L<R && L!=0 && L%rn!=0){
        ans += arr[L];
        L++;
    }
    //Middle Part
    while(L+rn<=R){
        int block_id = L/rn;
        ans += blocks[block_id];
        L += rn;
    }
    //Right Part
    while(L<=R){
        ans += arr[L];
        L++;
    }
    return ans;
}

void update(int *blocks,int *arr,int i,int value,int rn){
    int block_id = i/rn;
    blocks[block_id] += (value-arr[i]);
    arr[i] = value;
}

int main()
{
    int a[] = {1,3,5,2,7,6,3,1,4,8};
    int n = sizeof(a)/sizeof(int);

    int rn = sqrt(n);
    int blocks[rn+1] = {0};
    //Build a Blocks Araay
    int blocks_id = -1;
    for(int i=0;i<n;i++){
        if(i%rn==0){
            blocks_id++;
        }
        blocks[blocks_id] += a[i];
    }

    // for(int i=0;i<=blocks_id;i++){
    //     cout<<blocks[i]<<" ,";
    // }    
    // Queries
    int l,r;
    cin>>l>>r;
    update(blocks,a,2,15,rn);
    cout<<query(blocks,a,2,8,rn);

    return 0;
}