#include<bits/stdc++.h>
using namespace std;
int BinarySearch(int arr[],int low,int high,int ele)
{
    if(low>high)
        return -1;
    int mid = (low+high)/2;
    if(arr[mid]==ele)
        return mid;
    
    if(arr[low]<=arr[mid])
    {
        if(ele>=arr[low] && ele<=arr[mid])
            return BinarySearch(arr,low,mid-1,ele);
        return BinarySearch(arr,mid+1,high,ele);
    }
    if(ele>=arr[mid]&&ele<=arr[high])
        return BinarySearch(arr,mid+1,high,ele);

    return BinarySearch(arr,low,mid-1,ele);    

}
int main()
{
    int arr[] = {4,5,6,7,8,9,1,2,3};
    int n = sizeof(arr)/sizeof(int);
    int ele = 0;
    int idx = BinarySearch(arr,0,n-1,ele);
    if(idx==-1)
        cout<<"Element does not exist"<<endl;
    else
        cout<<"Element found at index "<<idx<<endl;
}