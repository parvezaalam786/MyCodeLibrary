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


int threeSumClosest(vector<int>& nums, int target) 
{
    int n = nums.size();
    sort(nums.begin(),nums.end());
    int sum1 = 9999999;
    for(int i=0;i<n;i++)
    {
        int l = i+1;
        int r = n-1;
        while(l<r)
        {
            int sum = nums[i]+nums[l]+nums[r];
            if(sum == target)
                return target;
            else if(sum<target)
                l++;
            else 
                r--;
            if( abs(target-sum1)>abs(target-sum) )
            {
                sum1 = sum;
            }
        }
    }
    return sum1;        
}
int main()
{
    fast_io;
    //input;
    //output;
   vector<int> v1;
   v1 = {-1,2,1,-4};
   int ans = threeSumClosest(v1,1);
   cout<<ans<<endl;
    return 0;
}