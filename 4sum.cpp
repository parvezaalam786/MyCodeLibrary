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


vector<vector<int>> countQuadruplets(vector<int>& nums, int target)
{
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int> > ans;
    for(int i=0;i<n-3;i++)
    {
        for(int j=i+1;j<n-2;j++)
        {
            int l = j+1; 
            int r = n-1;
            while(l<=r)
            {
                if((nums[i]+nums[j]+nums[l]+nums[r]==target)) 
                {
                    vector<int> v1;
                    if(l<r)
                    {
                        v1 = {nums[i],nums[j],nums[l],nums[r]};
                        ans.push_back(v1);
                    }
                    
                    int front = nums[l];
                    l++;
                    while(l<r&&front==nums[l]) l++;
                    int back = nums[r];
                    r--;
                    while(l<r&&back==nums[r]) r--;
                }
                else if(nums[i]+nums[j]+nums[l]+nums[r]<target)
                    l++;
                else if(nums[i]+nums[j]+nums[l]+nums[r]>target)
                    r--;
            }
        }
    }
    set<vector<int>> s1;
    for(int i=0;i<ans.size();i++)
    {
        s1.insert(ans[i]);
    }
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
    vector<int> v1;
    v1 = {1, 0, -1, 0, -2, 2};
    vector<vector<int> > ans;
    ans = countQuadruplets(v1,0);
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