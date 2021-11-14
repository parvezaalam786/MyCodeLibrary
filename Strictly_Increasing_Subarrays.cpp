
#include<bits/stdc++.h>
using namespace std;

//Here the complexity is O(M) where M is the no. of subarrays.
int IncreasingSubarrays1(int arr[],int n)
{
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[j+1]>arr[j])
                cnt++;
            else 
                break;   
        }
    }
    return cnt;
}

//Here the time complexity is O(n)
//we will add the no of the subarrays of strictly increasing subarrays n*(n-1)/2
int IncreasingSubarrays2(int arr[],int n)
{
    int cnt = 1,ans = 0;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i+1]>arr[i])
            cnt++;
        else
        {
            ans += (((cnt)*(cnt-1))/2);
            cnt = 1;
        }    
    }
    if(cnt>1)
        ans += (((cnt)*(cnt-1))/2);
    return ans;
}


int main()
{
    int arr[] = {1,2,3,4};
    int n = sizeof(arr)/sizeof(int);
    int ans = IncreasingSubarrays1(arr,n);
    cout<<ans<<endl;

    ans = IncreasingSubarrays2(arr,n);
    cout<<ans<<endl;

    return 0;
}