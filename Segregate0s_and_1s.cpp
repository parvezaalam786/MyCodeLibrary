#include<bits/stdc++.h>
using namespace std;

void segregate(int arr[],int n)
{
    int left = 0;
    int right = n-1;
    while(left<right)
    {
        while(arr[left]==0&&left<right)
            left++;
        while(arr[right]==1&&left<right)
            right--;
        if(left<right)
        {
            arr[left] = 0;
            arr[right] = 1;
            left++;
            right--;
        }    
    }
}
int main()
{
    int arr[] = {0,1,0,1,0,1,0,0,1,1,0,1};
    int n = sizeof(arr)/sizeof(int);
    segregate(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}