#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
long long int a,b,c,d;
 
void multiply(vector<vector<long long int>> &ans,vector<vector<long long int>> v)
{
    vector<vector<long long int>> copy = ans;
    
    int n = ans.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans[i][j] = 0;
            for(int k=0;k<n;k++)
            {
                ans[i][j] += ((copy[i][k]*v[k][j])%MOD);
                ans[i][j]%=MOD;
            }
        }
    }
}
long long int fast_fib(long long int n)
{
    if(n==1LL)return 2;
    if(n==2LL)return 3;
    
    vector<vector<long long int>> v = {{1,1},{1,0}};
    vector<vector<long long int>> ans = {{1,0},{0,1}};
    n-=2;
    while(n)
    {
        if(n&1)multiply(ans,v);
        multiply(v,v);
        
        // cout<<n<<"->> "<<endl;
        // for(auto it:v)
        // {
        //     for(auto i:it)cout<<i<<" ";cout<<endl;
        // }
        // cout<<endl;
        n/=2;
        
    }
    return (ans[0][0]*3LL+ans[0][1]*2LL)%MOD;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;        /* nth value to be found */
        scanf("%lld",&n);
        
        
        printf("%lld\n",fast_fib(n));
        
    }
    return 0;
    
}