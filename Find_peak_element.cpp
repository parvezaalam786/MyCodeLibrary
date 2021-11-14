//Peak element is defined as the element which is greater than its neighbours
#include<bits/stdc++.h>
using namespace std;
int findPeakutil(int arr[],int low,int high,int n)
{
    int mid = low+(high-low)/2;
    if((mid==0||arr[mid-1]<=arr[mid])&&(mid==n-1||arr[mid+1]<=arr[mid]))
        return mid;
    else if(mid>0&&arr[mid+1]>arr[mid])
        return findPeakutil(arr,low,(mid-1),n);
    else 
        return findPeakutil(arr,(mid+1),high,n);        
}

int main()  
{  
    int arr[] = {1, 3, 20, 4, 1, 0};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    cout << "Index of a peak point is " 
         << findPeakutil(arr,0,n-1,n);  
    return 0;  
}  