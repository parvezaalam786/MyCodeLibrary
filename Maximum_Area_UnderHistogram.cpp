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

int maxAreaHistogram(int arr[],int n)
{
  stack<int> s1;
  int tp = 0;
  int area = 0,maxArea = 0;
  int i = 0;
  while(i<n)
  {
    if(s1.empty()||arr[i]>=arr[s1.top()])
    {
      s1.push(i);
      i++;
    }  
    else
    {
      tp = s1.top();
      s1.pop();
      if(s1.empty())
      {
        area = arr[tp]*i;
      } 
      else
      {
        area = arr[tp]*(i-s1.top()-1);
      }
      if(area>maxArea)
        maxArea = area;
    }    
  }
  while(s1.empty()==false)
  {
    tp = s1.top();
    s1.pop();
    if(s1.empty())
      {
        area = arr[tp]*i;
      } 
      else
      {
        area = arr[tp]*(i-s1.top()-1);
      }
      if(area>maxArea)
        maxArea = area;
  }
  return maxArea;
}

int main()
{
    fast_io;
    ///input;
    ///output;
    
    int arr[] = {6,2,5,4,5,1,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxAreaHistogram(arr,n)<<endl;
    return 0;
}