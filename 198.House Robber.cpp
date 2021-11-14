class Solution {
public:
int rob(vector<int>& nums) {
    int i,n = nums.size();
    vector<int> dp(n+2);
    for(int i=0;i<n;i++){
        dp[i+2] = dp[i+1];
        dp[i+2] = max(dp[i+2],dp[i]+nums[i]);
    }
    return dp[n+1];
}
};