//A majority element is one which has occurence of more than n/2 times
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1,2,3,4,1,2,2,2,2,2,4};
    int n = sizeof(arr)/sizeof(int);
    unordered_map<int,int> m1;
    for(int i=0;i<n;i++)
    {
        if(m1.count(arr[i]))
            m1[arr[i]] += 1;
        else    
            m1[arr[i]] = 1;
    }
    int ans = -1;
    for(auto it1 : m1)
    {
        if(it1.second>n/2)
        {
            ans = it1.first;
        }
        // cout<<it1.first<<" "<<it1.second<<endl;
    }
    if(ans==-1)
        cout<<"None";
    else 
        cout<<ans<<endl;   
    return 0;
}