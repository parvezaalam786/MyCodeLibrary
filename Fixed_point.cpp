//Fixed point is defined as the index at which at the value at that index is equal to it.
//Find the fixed point if it is in the array.The array is sorted.

#include<bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[],int low,int high)
{
    if(high>=low)
    {
        int mid = (low+high)/2;
        if(mid==arr[mid])
            return mid;
        if(mid>arr[mid])
            return BinarySearch(arr,mid+1,high);
        else 
            return BinarySearch(arr,low,mid-1);    
    }
    return -1;
}
int main()
{
    int arr[] = {-10,-1,0,3,10,11,30,50,100};
    int n = sizeof(arr)/sizeof(int);
    int ans = BinarySearch(arr,0,n-1);
    if(ans==-1)
        cout<<"No fixed element found"<<endl;
    else 
        cout<<"Fixed element found at index "<<ans<<endl;
    return 0;    
}