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

vector<int> spiralOrder(const vector<vector<int> > &A) 
{
	int m = A.size();
	int n = A[0].size();

	int T = 0,B = m-1,L = 0,R = n-1;
	vector<int> ans;
	int dir = 0;
	while(T<=B&&L<=R)
	{
		if(dir==0)
		{
			for(int i=L;i<=R;i++)
				ans.eb(A[T][i]);
			T++;
		}
		else if(dir==1)
		{
			for(int i=T;i<=B;i++)
				ans.eb(A[i][R]);
			R--;
		}
		else if(dir==2)
		{
			for(int i = R;i>=L;i--)
				ans.eb(A[B][i]);
			B--;
		}
		else if(dir==3)
		{
			for(int i=B;i>=T;i--)
				ans.eb(A[i][L]);
			L++;
		}
		dir = (dir+1)%4;
	}
	return ans;
}


int main()
{
    fast_io;
    //input;
    //output;
   vector<vector<int> > v1;
   v1 = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
   vector<int> ans = spiralOrder(v1);
   for(int i=0;i<ans.size();i++)
   {
	   cout<<ans[i]<<" ";
   }
    return 0;
}