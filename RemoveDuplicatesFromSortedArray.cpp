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

int removeDuplicates(vector<int>& nums)
{
    int n = nums.size();
    int i=0,j=1;
    for(j=1;j<n;j++)
    {
        if(nums[i]!=nums[j])
        {
            nums[i+1] = nums[j];
            i++;
        }
    }    
    if(i+1>=n)
        i=i-2;
    return i+1;
}

int main()
{
    fast_io;
    //input;
    //output;
    vector<int> v1;
    v1 = {1,1,1,2,2,2,3,4};
    int len = removeDuplicates(v1);
    for(int i=0;i<len;i++)
     cout<<v1[i]<<" ";
   
    return 0;
}