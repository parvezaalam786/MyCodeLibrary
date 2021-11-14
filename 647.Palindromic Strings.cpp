#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    vector<vector<int>> dp,vis;
    int fun(int i,int j,string &s){
        if(i>j)//for even length
            return 1;
        if(i==j)//for one length string
            return 1;
        int &ans = dp[i][j];
        if(vis[i][j])
            return ans;    
        vis[i][j] = 1;    
        if(s[i]!=s[j])
            return ans=0;
        return ans = fun(i+1,j-1,s);    
    }

    int countSubstrings(string s) {
        int len = s.size();
        dp.resize(len,vector<int>(len,-1));
        vis.resize(len,vector<int>(len,0));
        int count = 0;
        for(int i=0;i<len;i++){
            for(int j=i;j<len;j++){
                count+=fun(i,j,s);
            }
        }
        return count;
    }
};
int main()
{
    string s = "aaa";
    Solution s1;
    cout<<s1.countSubstrings(s);
    return 0;
}