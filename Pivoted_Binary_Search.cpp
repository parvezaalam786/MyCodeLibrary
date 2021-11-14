#include<bits/stdc++.h>
using namespace std;
int BinarySearch(int arr[],int low,int high,int ele)
{
    if(low>high) return -1;
    int mid = (low+high)/2;

    if(ele==arr[mid])
        return mid;
    if(ele>arr[mid])
        return BinarySearch(arr,mid+1,high,ele);

    return BinarySearch(arr,low,mid-1,ele);
}

int findPivot(int arr[],int low,int high)
{
    if(high<low) return -1;
    if(high==low) return low;

    int mid = (low+high)/2;

    if(mid<high && arr[mid]>arr[mid+1])
        return mid;

    if(mid>low && arr[mid]<arr[mid-1])
        return (mid-1);
    
    if(arr[low]>=arr[mid])
        return findPivot(arr,low,mid-1);
    
    return findPivot(arr,mid+1,high);
}

int pivotedBinarySearch(int arr[],int n,int ele)
{
    int pivot = findPivot(arr,0,n-1);
    if(pivot==-1)
        return BinarySearch(arr,0,n-1,ele);

    if(arr[pivot]==ele)
        return pivot;
    
    if(arr[0]<=ele)
        return BinarySearch(arr,0,pivot-1,ele);
    return BinarySearch(arr,pivot+1,n-1,ele);
}
int main()
{
    int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}; 
  int n = sizeof(arr1)/sizeof(arr1[0]); 
  int key = 3; 
    
  // Function calling 
  cout << "Index of the element is : " <<  
           pivotedBinarySearch(arr1, n, key); 
             
  return 0;     

}