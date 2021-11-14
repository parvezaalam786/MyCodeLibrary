#include<bits/stdc++.h>
using namespace std;
class Solution {
    const int inf = 1e8;
    vector<vector<int>> dp,vis;
public:
    int go(int x,int y,vector<vector<int>> &A){  //The three movements that we can perform are(x+1,y),(x+1,y-1) and (x+1,y+1).
        
        if(x==A.size()) return 0;
        if(y==A[0].size()||y==-1)
            return inf;

        int &ans = dp[x][y];// Here it is storing the pre-computations 
        if(vis[x][y]) return ans;

        ans = min(ans,A[x][y]+go(x+1,y,A));
        ans = min(ans,A[x][y]+go(x+1,y-1,A));
        ans = min(ans,A[x][y]+go(x+1,y+1,A));
        
        vis[x][y] = 1;
        return ans;
    }
    int minFallingPathSum(vector<vector<int>>& A) {
        if(A.empty())
         return 0;
        int rows = A.size();
        int cols = A[0].size();
        dp.resize(rows,vector<int>(cols,INT_MAX));
        vis.resize(rows,vector<int>(cols,0));
        
        int ans = INT_MAX;
        for(int i=0;i<cols;i++){
            ans = min(ans,go(0,i,A));
        }
        return ans;
    }
};

int main()
{
    vector<vector<int> > A{ {1,2,3},
    {4,5,6},
    {7,8,9}
    };

    Solution a1;
    cout<<a1.minFallingPathSum(A);
    return 0;
}