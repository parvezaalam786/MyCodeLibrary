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
int maxArea(vector<int>& height)
{
    int n = height.size();
    int ans = INT_MIN;
    int l = 0,r = n-1;
    while(l<r)
    {
        ans = max(ans,min(height[l],height[r])*(r-l));
        if(height[l]<height[r])
            l++;
        else
            r--;
    }
    return ans;
}

int main()
{
    fast_io;
    //input;
    //output;
    vector<int> v1;
    v1 = {1,8,6,2,5,4,8,3,7};
    int ans = maxArea(v1);
    cout<<ans<<endl;   
    return 0;
}