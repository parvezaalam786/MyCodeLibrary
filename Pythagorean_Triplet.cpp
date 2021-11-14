#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
bool isTriplet(int arr[],int n)
{
    for(int i=0;i<n;i++)
        arr[i] *= arr[i];
    sort(arr,arr+n);
    for(int i=n-1;i>=2;i--)
    {
        int l = 0;
        int r = i-1;
        while(l<r)
        {
            if(arr[l]+arr[r]==arr[i])
                return true;
            (arr[l]+arr[r]<arr[i])?l++:r--;    
        }
    }    
    return false;
}
int main()
{
    int arr[] = {3,1,4,6,5};
    int n = sizeof(arr)/sizeof(int);
    bool ans = isTriplet(arr,n);
    if(ans)
        cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;    
}