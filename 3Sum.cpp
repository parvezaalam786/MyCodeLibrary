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

vector<vector<int>> threeSum(vector<int>& nums)
{
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    int n = nums.size();
    for(int i=0;i<n;i++)
    {
        int l = i+1;
        int r = n-1;
        while(l<r)
        {
            if(nums[i]+nums[l]+nums[r]==0)
            {
                vector<int> v1;
                v1 = {nums[i],nums[l],nums[r]};
                ans.push_back(v1);
                int front = nums[l];
                l++;
                while(l<r&&nums[l]==front) l++;
                int back = nums[r];
                r--;
                while(l<r&&nums[r]==back) r--;
            }
            else if(nums[i]+nums[l]+nums[r]<0)
                l++;
            else
                r--;
        }
    }
    set<vector<int>> s1;
    for(int i=0;i<ans.size();i++)
        s1.insert(ans[i]);
    ans.clear();
    for(auto i:s1)
        ans.push_back(i); 
    return ans; 
}

int main()
{
    fast_io;
    //input;
    //output;
    vector<vector<int> > ans;
    vector<int> v1;
    v1 = {-1,0,1,2,-1,-4};
    ans = threeSum(v1);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
   
    return 0;
}