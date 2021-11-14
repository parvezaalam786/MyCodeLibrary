///Count of Numbers in a Range where digit d occurs exactly K times

#include<bits/stdc++.h>
using namespace std;

vector<int> num;
int a,b,d,k;
int dp[20][20][2];
/// dp[p][c][f] = Number of valid number <= b from this state
/// p = current position from left side
/// c = number of times we have placed the digit d so far
/// f = the number we are building has already become smaller than b? 0 = no , 1 = yes

int call(int pos,int cnt,int f)
{
   if(cnt>k) return 0;
   if(pos==num.size())
   {
      if(cnt==k)
         return 1;
      return 0;
   }
   if(dp[pos][cnt][f]!=-1)
      return dp[pos][cnt][f];
   
   int res = 0;
   int limit;
   if(f==0)
   {
      limit = num[pos];
   }
   else
   {
      limit = 9;
   }
   for(int dig=0;dig<=limit;dig++)
   {
      int new_f = f;
      int new_cnt = cnt;
      if(f==0 && dig<limit)
         new_f = 1;
      if(dig==d)
         new_cnt++;
      if(new_cnt<=k)
         res += call(pos+1,new_cnt,new_f);         
   }
   return dp[pos][cnt][f] = res;
}

int solve(int b)
{
   num.clear();
   while(b>0)
   {
      num.push_back(b%10);
      b/=10;
   }
   reverse(num.begin(),num.end());
   memset(dp,-1,sizeof(dp));
   int res = call(0,0,0);
   return res;
}

int main()
{
   cin>>a>>b>>d>>k;
   int res = solve(b) - solve(a-1);
   cout<<res<<"\n";
   return 0;
}