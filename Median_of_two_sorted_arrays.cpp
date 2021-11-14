#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast_io ios::sync_with_stdio(false);cin.tie(NULL);
#define input freopen("Test.txt","r",stdin)
#define output freopen("Output.txt","w",stdout);
#define what_is(x) cout<<#x<<" is "<<x<<endl;
#define pb push_back
#define eb emplace_back
#define inf 1000000000
const double pi = 3.141592653589793238460;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
    if(nums1.size()>nums2.size())
        return findMedianSortedArrays(nums2,nums1);
    int n1 = nums1.size();
    int n2 = nums2.size();
    
    int low = 0,high = n1;
    while(low<=high)
    {
        int part1 = (low+high)/2;
        int part2 = (n1+n2+1)/2-part1;

        int a1 = (part1==0)?INT_MIN:nums1[part1-1];
        int a2 = (part1==n1)?INT_MAX:nums1[part1];

        int b1 = (part2==0)?INT_MIN:nums2[part2-1];
        int b2 = (part2==n2)?INT_MAX:nums2[part2];

        if(a1<=b2&&b1<=a2)
        {
            if((n1+n2)%2==0)
                return (double)((max(a1,b1)+min(a2,b2))/2.0);
            else 
                return (double)((2.0*max(a1,b1))/2.0);
        }
        else if(a1>b2)
            high = part1-1;
        else
            low = part1+1;
    }    
}

int main()
{
    fast_io;
    //input;
    //output;
    vector<int> num1,num2;
    num1 = {-5,3,6,12,15};
    num2 = {-12,-10,-6,-3,4,10};
    double ans = findMedianSortedArrays(num1,num2);
    cout<<ans<<endl;

    num1 = {2,3,5,8};
    num2 = {10,12,14,16,18,20};
    ans = findMedianSortedArrays(num1,num2);
    cout<<ans<<endl;

    num1 = {1,3,8,9,15};
    num2 = {7,11,18,19,21,25};
    ans = findMedianSortedArrays(num1,num2);
    cout<<ans<<endl;

    num1 = {23,26,31,35};
    num2 = {3,5,7,9,11,16};
    ans = findMedianSortedArrays(num1,num2);
    cout<<ans<<endl;   

    num1 = {1,3};
    num2 = {2};
    ans = findMedianSortedArrays(num1,num2);
    cout<<ans<<endl;

    return 0;
}