#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    //freopen("Test.txt","r",stdin);
    fast_io;
    int T;
    int arr1[3],arr2[3];
    cin>>T;
    while(T--){
        for(int i=0;i<3;i++) cin>>arr1[i];
        for(int i=0;i<3;i++) cin>>arr2[i];
        for(int i=1;i<3;i++){
            int key1 = arr1[i];
            int key2 = arr2[i];
            int j = i-1;
            while(j>=0&&arr1[j]>key1){
                arr1[j+1] = arr1[j];
                arr2[j+1] = arr2[j];
                j--;
            }
            arr1[j+1] = key1;
            arr2[j+1] = key2;
        }
        bool fair =is_sorted(arr2,arr2+3);
        for(int i=0;i<2;i++){
            if(arr1[i]==arr1[i+1]&&arr2[i]!=arr2[i+1]||arr1[i+1]>arr1[i]&&arr2[i+1]==arr2[i])
                fair = false;
        }
        if(fair) cout<<"FAIR"<<endl;
        else cout<<"NOT FAIR"<<endl;
    }
    return 0;
}