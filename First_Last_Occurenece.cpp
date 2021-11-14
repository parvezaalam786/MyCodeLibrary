#include<bits/stdc++.h>
using namespace std;
int first(vector<int>& nums,int low,int high,int target)
{
    if(high>=low){
        int mid = (low+high)/2;
        if((mid==0 || target>nums[mid-1])&&nums[mid]==target)
            return mid;
        else if(target>nums[mid])
            return first(nums,mid+1,high,target);
        else
            return first(nums,low,mid-1,target);
    }
    return -1;
}
int last(vector<int>& nums,int low,int high,int target)
{
    int n = nums.size();
    if(high>=low){
        int mid = (low+high)/2;
        if((mid==n-1||nums[mid+1]>target)&&nums[mid]==target)
            return mid;
        else if(target<nums[mid])
            return last(nums,low,mid-1,target);
        else return last(nums,mid+1,high,target);        
    }
    return -1;
}
vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    int l = first(nums,0,n-1,target);
    int r = last(nums,0,n-1,target);        
    vector<int> v1;
    v1.push_back(l);
    v1.push_back(r);
    return v1;
}

int main()
{
    vector<int> arr{1, 2, 2, 2, 2, 3, 4, 7, 8, 8}; 
    int n = sizeof(arr)/sizeof(int); 
  
    int x = 5; 
    vector<int> r;
    r = searchRange(arr,x);
    cout<<r[0]<<" "<<r[1];

}