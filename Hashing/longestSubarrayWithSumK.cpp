#include<bits/stdc++.h>
using namespace std;
#define ll          long long int
#define endl        "\n"
#define fast_io     ios::sync_with_stdio(false);cin.tie(NULL);
#define input       freopen("Test.txt","r",stdin)
#define output      freopen("Output.txt","w",stdout);
#define what_is(x)  cout<<#x<<" is "<<x<<endl;
#define pb          push_back
#define eb          emplace_back
#define inf         1000000000
const double pi = 3.141592653589793238460;
#define mod 1000000007

int longestSubarrayWithSumK(int *arr,int n,int k)
{
  unordered_map<int,int> m1;
  int pre = 0;
  int len = 0;
  for(int i=0;i<n;i++)
  {
    pre += arr[i];
    if(pre==k) len = max(len,i+1);
    if(m1.find(pre-k)!=m1.end())
    {
      len = max(len,i-m1[pre-k]);
    }
    else
      m1[pre] = i;
  }
  return len;
}

int main()
{
    fast_io;
    ///input;
    ///output;
    int n; cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    int k; cin>>k;
    int len = longestSubarrayWithSumK(arr,n,k);
    cout<<len<<endl;
    return 0;
}

/*
input:
5
1 -1 5 -2 3
3  

*/